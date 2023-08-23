#include "shell.h"

/**
 * _cd - fuction that changes the directory
 * @args: command
 * Return: result
 */

int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "_cd: expected argument to \"cd\"\n");
		return (1);
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("_cd");
			return (1);
		}
	}
	return (0);
}


/**
 * main_cd - main function
 * Return: 0
 */

int main_cd(void)
{
	char *args[] = {"cd", "/path/to/directory", NULL};

	_cd(args);

	return (0);
}