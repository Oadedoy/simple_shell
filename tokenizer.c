#include "shell.h"

/**
 * tokenize - Tokenizes a string.
 * @input: The string.
 * @args: list of arguments.
 * @arg_size: size of arguments.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
void tokenize(char *input, char **args, size_t args_size) {
    size_t arg_count = 0;
    char *token;
    
    token = strtok(input, " ");

    while (token != NULL && arg_count < args_size - 1) {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }

    args[arg_count] = NULL;
}
