#include "mainshell.h"
#include <sys/wait.h>

/**
 * executer - The function executes the command given by user.
 * @command: the command given by user.
 * Return: Always 0 (Success)
 */
void executer(const char *command)
{
	char const **args = malloc(2 * sizeof(char *));
	pid_t child_ID;

	if (args == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	args[0] = command;
	args[1] = NULL;

	child_ID = fork();
	if (child_ID == -1)
	{
		perror("child_ID not created, fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	else if (child_ID == 0)
	{
		execve(command, (char *const *)args, NULL);
		perror("Execution not successful");
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
return;
}
