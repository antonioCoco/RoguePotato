#include "Windows.h"
#include "stdio.h"

char gPipeName[MAX_PATH];

int RunRogueOxidResolver(char* listening_port);
void Usage();

int main(int argc, char** argv)
{
	int ret;
	char default_pipename[] = "RoguePotato";
	strcpy_s(gPipeName, MAX_PATH - 1, default_pipename);
	char* listening_port = NULL;

	while ((argc > 1) && (argv[1][0] == '-'))
	{
		switch (argv[1][1])
		{
		case 'l':
			++argv;
			--argc;
			listening_port = argv[1];
			break;

		case 'p':
			++argv;
			--argc;
			strcpy_s(gPipeName, MAX_PATH - 1, argv[1]);
			break;

		case 'h':
			Usage();
			exit(100);
			break;

		default:
			printf("Wrong Argument: %s\n", argv[1]);
			Usage();
			exit(-1);
		}
		++argv;
		--argc;
	}

	if (listening_port == NULL)
	{
		Usage();
		exit(-1);
	}

	ret = RunRogueOxidResolver(listening_port);
	return ret;
}

void Usage()
{
	printf("\n\n\tRogueOxidResolver\n\t@splinter_code & @decoder_it \n\n\n");

	printf("Mandatory args: \n"
		"-l listening_port: port to listen for RogueOxidResolver\n"
	);

	printf("\n\n");
	printf("Optional args: \n"
		"-p pipename_placeholder: placeholder to be used in the pipe name creation (default: RoguePotato)\n"
	);


	printf("\n\n");
	printf("Examples: \n"
		" - Run RogueOxidResolver on port 9999\n"
		"\tRogueOxidResolver.exe -l 9999\n"
		" - Run RogueOxidResolver on port 9999 and use a custom pipe name\n"
		"\tRogueOxidResolver.exe -l 9999 -p splintercode\n"
	);
}