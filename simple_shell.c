#include "shell.h"

/**
 * main - check if our shell is called
 * Return: 0 (if successful)
 */

int main(void)
{
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			interactive_shell();
		}
		else
		{
			non_interactive_shell();
		}
		return (0);
	}
}