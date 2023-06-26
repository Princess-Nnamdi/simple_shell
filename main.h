#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main(int ac, char **argv, char **env);
int _putchar(char c);
int executes_command(char **argv);
char *get_path(char *cmd);
int chill(void);
void environment(void);
ssize_t *_getline(char **ptr, size_t *n);

#endif
