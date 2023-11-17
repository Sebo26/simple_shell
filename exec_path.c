#include "mainshell.h"

/**
 * exec_path - The function executes the command given by user
 * following the PATH
 * @command: The command requested by user.
 * Return: 0
 */
void exec_path(const char *command)
{
const char *path;
path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
setenv("PATH", path, 1);

	if (chdir(path) == 0)
	{
		pid_t child_ID = fork();

		if (child_ID == -1)
		{
			perror("fork() error");
		}
		else if (child_ID == 0)
		{
			char *token;
			char *args[10];
			int arg_count = 0;

			token = strtok((char *)command, " ");
			while (token != NULL)
			{
				args[arg_count++] = token;
				token = strtok(NULL, " ");
			}
			args[arg_count] = NULL;

			execve(args[0], args, NULL);
			perror("execve() error");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		perror("chdir() error");
	}
return;
}
