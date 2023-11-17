#include "mainshell.h"
#include <sys/wait.h>

/**
 * exec_arg - The function handles command lines with arguments.
 * @command: The instruction given by the user.
 * Return: Always 0 (Success)
 */
void exec_arg(const char *command)
{
	char *argument[100];
	int number_of_arguments = 0;
	char *token;

	pid_t child_ID = fork();

	if (child_ID == -1)
	{
		perror("child_ID not created, fork");
		exit(EXIT_FAILURE);
	}
	else if (child_ID == 0)
	{
		token = strtok((char *)command, " ");
		while (token != NULL)
		{
			argument[number_of_arguments++] = token;
			token = strtok(NULL, " ");
		}
		argument[number_of_arguments] = NULL;
		execve(command, argument, NULL);

		printer("Command not executed.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
			wait(NULL);
	}
return;
}
