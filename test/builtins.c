#include "shell.h"

int ss_cd(char **args);
int ss_exit(char **args);
int ss_help(char **args);

char *builtin_str[] = {"cd", "exit", "help"};
int (*builtin_func[]) (char **) = {&ss_cd, &ss_exit, &ss_help};

/**
 * num_builtins - Returns the number of builtins for the shell
 * Return: The number of builtin functions.
 */

int num_builtins(void)
{
	return ((sizeof(builtin_str)) / (sizeof(char *)));
}

/**
 * ss_cd - Used to change directories while within the shell.
 * @args: Arguments
 * Return: 1
 */

int ss_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "ss: expected argument to \"cd\"\n");
	else
		if (chdir(args[1]) != 0)
			perror("ss");
	return (1);
}

/**
 * ss_exit - Used to exit the shell.
 * @args: Arguments
 * Return: 0
 */

int ss_exit(char **args)
{
	return (0);
}

/**
 * ss_help - Used to list the built-in functions of the shell.
 * Written in the style of a medieval herald.
 * @args: Arguments
 * Return: 1
 */

int ss_help(char **args)
{
	int i;

	printf("Welcome, my liege, to the Atlas Simple Shell;\n");
	printf("a joint endeavor of castles Griffith and Lockhart!\n");
	printf("Behold, the built in features of our mighty shell!\n");
	printf("Type the program names and arguments,\n");
	printf("then press thine enter key to execute your command!\n");
	for (i = 0; i < num_builtins(); i++)
		printf(" %s\n", builtin_str[i]);
	printf("Should you require more information, use the 'man' command\n");
	printf("to call upon the esteemed chronicler of the shell!\n");
	return (1);
}
