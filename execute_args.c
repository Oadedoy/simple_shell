#include "shell.h"

/**
 * execute_args - check if the command is in a process or builtin
 * @args: commands and its flags
 * Return: 1(on success), 0(on failure)
 */

int execute_args(char **args)
{
	char *builtin_func_list[] = {
		"cd",
		"env",
		"help",
		"exit",
	};
	int (*builtin_func[])(char **) = {
		&_cd,
        &_env,
		&_help,
		&my_exit,
	};
	unsigned int i;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (execute(args));
}