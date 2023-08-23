#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/*Function prototypes*/
void tokenize(char *input, char **args, size_t args_size);
void execute(char **args);

/*Helper prototypes*/
size_t custom_strlen(const char *str);

#endif /* SHELL_H */