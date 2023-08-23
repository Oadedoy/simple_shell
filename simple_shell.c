#include <stdio.h>
#include "simple_shell.h"

int main() {
    char *command = NULL;
    int exec_result, status;
    size_t command_size = 0;
    ssize_t read;
    pid_t pid;

    while (1) {
        
        printf("$ ");
        fflush(stdout);

        read = getline(&command, &command_size, stdin);

        if (read == -1) 
        {
            printf("\nShell terminated.\n");
            free(command);
            break;
        }
        command[strcspn(command, "\n")] = '\0';

        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {

            char *args[2];
            args[0] = command;
            args[1] = NULL;

            exec_result = execve(command, args, NULL);

            if (exec_result == -1) {
                printf("Command not found: %s\n", command);
                free(command);
                exit(EXIT_FAILURE);
            }
        } else {
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
