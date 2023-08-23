#include "shell.h"

/**
 * _exit - function that exit or terminate the shell
 * @args: command
 * Return: result
 */

int _exit(char **args)
{
	if (args[1] != NULL)
	{
		int exitcode = atoi(args[1]);

		exit(exitcode);
	}
	exit(0);
}

/**
 * _env - fuction that prints environment variable
 * @args: command
 * Return: result
 */

int _env(char **args)
{
	int x = 0;
	char *env_var;

	while ((env_var = getenv(args[x])) != NULL)
	{
		printf("%s\n", env_var);
		x++;
	}

	return (0);
}

/**
 * _help - function that display help message
 * @args: command
 * Return: result
 */

int _help(char **args)
{
	(void)args;

	printf("=== Custom Shell Help ===\n");
	printf("Available commands:\n");
	printf("cd [directory] - Change the current directory\n");
	printf("exit - Terminate the shell\n");
	printf("env - Display environment variables\n");
	printf("help - Display this help message\n");
	return (1);
}