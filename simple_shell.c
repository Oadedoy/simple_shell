#include "shell.h"

#define MAX_COMMAND_LENGTH 100

int main() {
    char *command = NULL;
    size_t command_size = 0, len;
    ssize_t read;
    char *args[MAX_COMMAND_LENGTH];

    while (1) {
        printf("$ ");
        fflush(stdout);

        read = getline(&command, &command_size, stdin);

        if (read == -1) {
            printf("\nShell terminated.\n");
            free(command);
            break;
        }

        len = custom_strlen(command);

        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }


        tokenize(command, args, MAX_COMMAND_LENGTH);

        execute(args);
    }

    free(command);
    return 0;
}