#include "shell.h"

/**
 * non_interactive_shell - unix command line interpreter
 * Return: 0
 */

void non_interactive_shell(void)
{
	char *ptr;
	char **args;
	int status = -1;

	do {
		ptr = read_stream();
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