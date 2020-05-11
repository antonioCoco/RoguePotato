#pragma once
#define PIPE_NAME L"RoguePotato"
#define THREAD_TIMEOUT 9000
BOOL EnablePriv(HANDLE, LPCTSTR);
int ExecuteSystem(wchar_t*, HANDLE);
void TriggerDCOM();
PSID BuildEveryoneSid();
BOOL AddTheAceDesktop(HDESK, PSID);
BOOL AddTheAceWindowStation(HWINSTA, PSID);
void Usage();
void TriggerDCOM();
DWORD WINAPI ThreadTriggerDCOM(LPVOID lParams);
void RoguePotato(wchar_t* commandline, wchar_t* pipe_placeholder, wchar_t* listening_port);
int RunRogueOxidResolver(char* listening_port);
int ExecuteSystem(wchar_t*, HANDLE);
int CreatePipeServer(wchar_t*);
int RunRogueOxidResolver(char* listening_port);
