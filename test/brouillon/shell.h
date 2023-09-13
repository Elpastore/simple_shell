#ifndef SHELL_H
#define SHELL_H

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

char *prompt(void);
char **_split(char *input);
int execute(char **tokens, char **argv);
char *non_interactive();
void free_array(char **tokens);

#endif
