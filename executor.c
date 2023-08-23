#include "shell.h"

/**
 * execute - function that create a new process
 *             and execute commands
 * @args: arrays of strings
 * Return: 1 (success) , 0(fails)
 */

int execute(char **args)
{
	pid_t _pid;
	int status;

	_pid = fork();
	if (_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("error in new_process: child process");
		}
		exit(EXIT_FAILURE);
	}
	else if (_pid < 0)
	{
		perror("error in new_process: forking");
	}
	else
	{
		do {
			waitpid(_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}