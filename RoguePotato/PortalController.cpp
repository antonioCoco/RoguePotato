#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "PortalController.h"

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

struct socket_pair {
    SOCKET src;
    SOCKET dst;
};

SOCKET sock_connect(char* target_addr, char* target_port)
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo* result = NULL, * ptr = NULL, hints;
    int iResult;

    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return INVALID_SOCKET;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    iResult = getaddrinfo(target_addr, target_port, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return INVALID_SOCKET;
    }

    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return INVALID_SOCKET;
        }

        iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return INVALID_SOCKET;
    }

    return ConnectSocket;
}

DWORD WINAPI GenericPortal(LPVOID lpParam)
{
    struct socket_pair* pair = (struct socket_pair*)lpParam;
    SOCKET SrcSocket = pair->src;
    SOCKET DstSocket = pair->dst;
    int iResult;
    int nBytes;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    free(pair);

    do {
        iResult = recv(SrcSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            nBytes = iResult;
            iResult = send(DstSocket, recvbuf, nBytes, 0);
            if (iResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(DstSocket);
                closesocket(SrcSocket);
                return 1;
            }
        }
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);

    closesocket(DstSocket);
    closesocket(SrcSocket);
    return 0;
}


void CreateBidirectionalPortal(SOCKET PortalSocket, SOCKET LocalResolverSocket)
{
    DWORD portalToResolverThreadId;
    DWORD resolverToPortalThreadId;
    struct socket_pair* pair1;
    struct socket_pair* pair2;

    pair1 = (struct socket_pair*) malloc(sizeof(struct socket_pair));
    
    if (pair1 == NULL) {
        printf("[-] Error malloc\n");
        return;
    }

    pair1->src = PortalSocket;
    pair1->dst = LocalResolverSocket;

    pair2 = (struct socket_pair*) malloc(sizeof(struct socket_pair));

    if (pair2 == NULL) {
        printf("[-] Error malloc\n");
        return;
    }

    pair2->src = LocalResolverSocket;
    pair2->dst = PortalSocket;

    CreateThread(NULL, 0, GenericPortal, (LPVOID)pair1, 0, &portalToResolverThreadId);
    CreateThread(NULL, 0, GenericPortal, (LPVOID)pair2, 0, &resolverToPortalThreadId);
}

int RunPortalController(char* portal_port, wchar_t* remote_ip, char* resolver_listening_port)
{
    int iResult;
    SOCKET ControllerSocket = INVALID_SOCKET;
    SOCKET PortalSocket = INVALID_SOCKET;
    SOCKET LocalResolverSocket = INVALID_SOCKET;
    const char* sendbuf = "this is a test";
    char remote_ip_str[256];
    char localhost[] = "127.0.0.1";

    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    snprintf(remote_ip_str, 255, "%ws", remote_ip);
    printf("[*] Connecting to remote portal - %s:%s\n", remote_ip_str, portal_port);
    ControllerSocket = sock_connect(remote_ip_str, portal_port);

    if (ControllerSocket == INVALID_SOCKET) {
        printf("[-] Failed to connect to remote portal\n");
        return 1;
    }

    printf("[*] Connecting to remote portal - SUCCESS\n");
    do {
        iResult = recv(ControllerSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            if (strcmp(recvbuf, ALLOC_RESOLVER_MSG) == 0) {
                printf("[*] Received ALLOC message. Connecting...\n");

                printf("[*] Connecting to %s:%s\n", localhost, resolver_listening_port);
                LocalResolverSocket = sock_connect(localhost, resolver_listening_port);
                
                if (LocalResolverSocket == INVALID_SOCKET) {
                    printf("[-] Failed to connect into LocalResolver\n");
                }

                PortalSocket = sock_connect(remote_ip_str, portal_port);

                if (PortalSocket == INVALID_SOCKET) {
                    printf("[-] Failed to connect into Portal\n");
                }

                if (LocalResolverSocket != INVALID_SOCKET && PortalSocket != INVALID_SOCKET) {
                    printf("[*] Creating Bidirectional portal\n");
                    CreateBidirectionalPortal(PortalSocket, LocalResolverSocket);
                }
            }
        }
        else if (iResult == 0)
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());

    } while (iResult > 0);

    // cleanup
    closesocket(ControllerSocket);
    WSACleanup();

    return 0;
}