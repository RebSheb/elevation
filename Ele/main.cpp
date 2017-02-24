#include <stdio.h>
#include <Windows.h>

char buf[MAX_PATH] = {};


void executeProgram(char*,const char*);

void main()
{



	if(!GetCurrentDirectory(sizeof(buf), buf))
	{
		printf("[Ele] - Failed to find current directory\n");
		return;
	}

	printf("[Ele] - %s\n", buf);

	if (buf[0] == 'C')
		executeProgram(buf, &buf[0]);

	else
		printf("[Buf[0]] : %s\n", &buf[0]);
		executeProgram(buf, &buf[0]);


	return;
}

void executeProgram(char *path, const char *drive)
{
	if (*drive == 'C')
	{
		char execPath[MAX_PATH + 1] = {};
		ZeroMemory(execPath, sizeof(execPath));
		strcat_s(execPath, sizeof(execPath), "/K cd ");
		strcat_s(execPath, sizeof(execPath), path);

		printf("[Ele] - execPath: %s\n", execPath);

		ShellExecute(NULL, "runas", "C:\\Windows\\System32\\cmd.exe", execPath, NULL, SW_SHOW);
		exit(0);
	}

	else
	{
		char execPath[MAX_PATH + 1] = {};
		ZeroMemory(execPath, sizeof(execPath));

		strcat_s(execPath, sizeof(execPath), "/K ");
		printf("Here: %s\n", execPath);
		strcat_s(execPath, sizeof(execPath), &drive[0]);
		printf("execPath 2:  %s\n\n", execPath);
		strcat_s(execPath, sizeof(execPath), " && cd ");

		printf("\n\n%s\n\n", path);

		printf("[Ele] - Different Drive: execPath: %s\n", execPath);

		ShellExecute(NULL, "runas", "C:\\Windows\\System32\\cmd.exe", execPath, NULL, SW_SHOW);
		exit(0);
	}

	//ShellExecute(NULL, "open", "C:\\Windows\\System32\\cmd.exe", "")
}
