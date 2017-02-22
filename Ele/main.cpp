#include <stdio.h>
#include <Windows.h>

char buf[MAX_PATH] = {};




void main()
{



	if(!GetCurrentDirectory(sizeof(buf), buf))
	{
		printf("[Ele] - Failed to find current directory\n");
		return;
	}

	printf("[Ele] - %s\n", buf);

	return;
}

void executeProgram(char *path)
{


	ShellExecute(NULL, "open", "C:\\Windows\\System32\\cmd.exe", "")
}
