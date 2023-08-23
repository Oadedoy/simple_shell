#include "shell.h"

/**
 * interactive_shell - Unix command line interpreter
 * Return: void
 */

void interactive_shell(void)
{
	char *ptr;
	char **args;
	int status = -1;

	do {
		printf("$ ");

		ptr = read_line();

		args = tokenize(ptr);

		status = execute_args(args);

		free(ptr);
		free(args);

		if (status >= 0)
		{
			exit(status);
		}
	} while (status == -1);
}