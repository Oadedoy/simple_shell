#include "shell.h"

/**
 * read_line - function that read line from the standard input.
 * Return: result
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("error while reading the line from the stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}