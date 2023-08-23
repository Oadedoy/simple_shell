#include "shell.h"

/**
 * read_stream - read a line from the stram
 * Return: result
 */

char *read_stream(void)
{
	int bufsize = 1024;
	char *p = malloc(sizeof(char *) * bufsize);
	int nchar, x = 0;

	if (p == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		nchar = getchar();
		if (nchar == EOF)
		{
			free(p);
			exit(EXIT_SUCCESS);
		}
		else if (nchar == '\n')
		{
			p[x] = '\0';
			return (p);
		}
		else
		{
			p[x] = nchar;
		}
		x++;
		if (x >= bufsize)
		{
			bufsize += bufsize;
			p = realloc(p, bufsize);
			if (p == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}