#include "mainshell.h"

/**
 * reader - The function reads the command given by user.
 * @command: The command given by the user.
 * @length: The size of command given by the user.
 * Return: Always 0 (Success)
 */
void reader(char *command, size_t length)
{
	if (fgets(command, length, stdin) == NULL)
	{
		if (feof(stdin))
		{
			printer("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			printer("Failed to read input.\n");
			exit(EXIT_FAILURE);
		}
	}
command[strcspn(command, "\n")] = '\0';
return;
}
