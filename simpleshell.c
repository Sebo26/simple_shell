#include "mainshell.h"

/**
 * main - Entry point
 * Description: Carries out functions that take place in a simple shell.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char command[100];

	while (1)
	{
		prompt();
		reader(command, sizeof(command));
		executer(command);
		exec_arg(command);
		exec_path(command);
		my_exit();
	}
return (0);
}
