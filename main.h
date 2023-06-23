#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>

int main(int ac, char **argv);
int executes_command(char **argv);
char *get_path(char *cmd);
int chill(void);

#endif
