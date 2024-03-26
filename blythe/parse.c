#include "shell.h"
/**
 * parse - Parse user input into distinct cmds and args.
 * @line - User input to be parsed
 * Return - A double array of cmds and their args.
 */

char ***parse(char *line)
{
	char *token;
	char ***commands = malloc(MAX_COMMANDS * sizeof(char **));
	int command_index = 0;

	if (commands == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, "|");

	while (token != NULL && command_index < MAX_COMMANDS)
	{
		char **args = malloc(MAX_ARGS * sizeof(char *));

		if (args == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		int arg_index = 0;
		char *arg_token = strtok(token, TOK_DELIM);

		while (arg_token != NULL && arg_index < MAX_ARGS - 1)
		{
			args[arg_index] = strdup(arg_token);

			if (args[arg_index] == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
			arg_index++;
			arg_token = strtok(NULL, TOK_DELIM);
		}
		args[arg_index] = NULL;
		commands[command_index] = args;
		command_index++;
		token = strtok(NULL, "|");
	}
	commands[command_index] = NULL;

	return commands;
}
