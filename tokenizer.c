#include "shell.h"

/**
 * tokenize - split a string into multiple strings
 * @ptr: the string to be slited.
 * Return: result
 */

char **tokenize(char *ptr)
{
	int bufsize = 64;
	int x = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *str;

	if (!tokens)
	{
		fprintf(stderr, "allocate error in split_line: tokens\n");
		exit(EXIT_FAILURE);
	}
	str = strtok(ptr, _DELIMITER);
	while (str != NULL)
	{
		if (str[0] == '#')
		{
			break;
		}
		tokens[x] = str;
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in split_line: tokensn");
				exit(EXIT_FAILURE);
			}
		}
		str = strtok(NULL, _DELIMITER);
	}
	tokens[x] = NULL;
	return (tokens);
}