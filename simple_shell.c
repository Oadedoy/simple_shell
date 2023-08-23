#include <stdio.h>
#include "simple_shell.h"

int main() {
    char *command = NULL;
    size_t command_size = 0;

    while (1) {
        // Display the prompt
        printf("$ ");
        fflush(stdout);

        // Read the command using getline
        ssize_t read = getline(&command, &command_size, stdin);

        if (read == -1) {
            // Handle end of file (Ctrl+D)
            printf("\nShell terminated.\n");
            free(command);
            break;
        }

        // Remove the newline character from the input
        command[strcspn(command, "\n")] = '\0';

        // Fork a child process to execute the command
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            // Child process

            // Split the command into tokens
            char *args[2];
            args[0] = command;
            args[1] = NULL;

            // Execute the command using execve
            int exec_result = execve(command, args, NULL);

            if (exec_result == -1) {
                // Handle command not found
                printf("Command not found: %s\n", command);
                free(command);
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
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

    free(command);
    return 0;
}
