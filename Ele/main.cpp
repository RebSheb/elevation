#include <stdio.h>
#include <Windows.h>

char buf[MAX_PATH] = {};


void executeProgram(char*);
char GetDriveString(char*);

void main()
{



	if(!GetCurrentDirectory(sizeof(buf), buf))
	{
		printf("[Ele] - Failed to find current directory\n");
		return;
	}

	printf("[Ele] - %s\n", buf);

	executeProgram(buf);

	return;
}

void executeProgram(char *path)
{
	if (GetDriveString(path) == '1')
	{
		char execPath[MAX_PATH + 1] = {};
		ZeroMemory(execPath, sizeof(execPath));
		strcat_s(execPath, sizeof(execPath), "/K cd ");
		strcat_s(execPath, sizeof(execPath), path);

		printf("[Ele] - execPath: %s\n", execPath);

		ShellExecute(NULL, "open", "C:\\Windows\\System32\\cmd.exe", execPath, NULL, SW_SHOW);
	}

	//ShellExecute(NULL, "open", "C:\\Windows\\System32\\cmd.exe", "")
}


char GetDriveString(char *path)
{
	if(buf[0] == 'C')
	{
		printf("[Ele] - Drive is C:\n");
		return '1';
	}

	LPTSTR volName;
	GetVolumePathName(path, volName, sizeof(LPTSTR));
	printf("[Ele] - Drive isn't C:\n%d\n",volName);
	return '2';
}