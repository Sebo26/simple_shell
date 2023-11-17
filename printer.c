#include "mainshell.h"

/**
 * printer - the function prints text from user.
 * @text: The command or instrucion that will be entered by user.
 */

void printer(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
return;
}
