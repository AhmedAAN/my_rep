#include "shell.h"

/***
 *
 */
void process(char *filepath, char *args[MAX_ARGUMENTS], char **env)
{
    pid_t pid;

    pid = fork();
	if (pid < 0)
	{
		printf("Fork failed\n");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(filepath, args, env);
		printf("Error: command not found\n");
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}
