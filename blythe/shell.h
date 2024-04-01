#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#define TOK_DELIM " \t\r\n\a"
#define TOK_BUFSIZE 64
#define MAX_CMDS 16
#define MAX_ARGS 64
#define MAX_LINE_LENGTH 256
#define MAX_BUILTINS 3

int main(char **env);
char ***parse(char *line);
char **prompt();
void fork_exec(char **command, char **env);
void find_path(char ***cmds, char **env);
int num_builtins(char **);
void ss_cd(char **cmds);
void ss_exit(void);
void ss_help(void);

#endif
