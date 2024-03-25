#ifndef _MAIN_H_
#define _MAIN_H_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **env);
void ss_loop(void);
char *ss_readline(void);
char **ss_splitline(char *line);
int ss_launch(char **args);
int ss_cd(char **args);
int ss_help(char **args);
int ss_exit(char **args);
int ss_execute(char **args);

#endif
