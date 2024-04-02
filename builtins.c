#include "shell.h"

char *builtins[] = {"cd", "exit", "help"};

/**
 * ss_cd - Used to change directories while within the shell.
 * @args: Arguments
 * Return: 1
 */

void ss_cd(char **cmds)
{
	if (cmds[1] == NULL)
		fprintf(stderr, "ss: expected argument to \"cd\"\n");
	else
		chdir(cmds);
}

/**
 * ss_exit - Used to exit the shell.
 * Return: ''
 */

void ss_exit(void)
{
	return;
}

/**
 * ss_help - Used to list the built-in functions of the shell.
 * Written in the style of a medieval herald.
 * Return: 1
 */

void ss_help(void)
{
	int i;

	printf("Welcome, my liege, to the Atlas Simple Shell;\n");
	printf("a joint endeavor of castles Griffith and Lockhart!\n");
	printf("Behold, the built in features of our mighty shell!\n");
	printf("Type the program names and arguments,\n");
	printf("then press thine enter key to execute your command!\n");
	for (i = 0; i < MAX_BUILTINS; i++)
		printf(" %s\n", builtins[i]);
	printf("Should you require more information, use the 'man' command\n");
	printf("to call upon the esteemed chronicler of the shell!\n");
}
