#include "mainshell.h"
#include <sys/wait.h>

/**
 * executer - The function executes the command given by user.
 * @command: the command given by user.
 * Return: Always 0 (Success)
 */
void executer(const char *command)
{
	char *args[2];
	pid_t child_ID;

	args[0] = (char *)command;
	args[1] = NULL;

	child_ID = fork();
	if (child_ID == -1)
	{
		perror("child_ID not created, fork");
		exit(EXIT_FAILURE);
	}
	else if (child_ID == 0)
	{
		execve(command, args, NULL);
		perror("Execution not successful");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
return;
}
