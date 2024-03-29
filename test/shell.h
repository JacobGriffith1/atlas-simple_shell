#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - Struct that contains data pertaining to the activity within the shell.
 * @av: Argument vector.
 * @input: Input command written by the user.
 * @args: Arguments; tokens of the command line.
 * @status: Last status of the shell.
 * @counter: Line counter.
 * @_environment: Environmental variable.
 * @pid: Process ID of the shell.
 */

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;



#endif
