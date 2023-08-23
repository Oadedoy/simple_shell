#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define _DELIMITER " \t\r\n\a\"\;"
extern char **environ;

void interactive_shell(void);
void non_interactive_shell(void);
char *read_line(void);
char **tokenize(char *ptr);
int execute_args(char **args);
int execute(char **args);
char *read_stream(void);
int _cd(char **args);
int my_exit(char **args);
int print_environment();
int _help(char **args);

#endif