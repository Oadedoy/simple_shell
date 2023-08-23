#include "shell.h"

/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 *
 * Return: If an error occurs - a corresponding error code.
 *         if sucessful - The exit value of the last executed command.
 */
void execute(char **args) {
    pid_t pid;
    
    pid = fork();

    if (pid == -1) {
        perror("fork");
    } else if (pid == 0) {
        int exec_result = execve(args[0], args, NULL);

        if (exec_result == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) != 0) {
                printf("Command failed with exit status %d\n", WEXITSTATUS(status));
            }
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        }
    }
}