#include "shell.h"
/**
 * parse - Parse user input into distinct cmds and args.
 * @line: User input to be parsed
 * Return: A double array of cmds and their args.
 */

char ***parse(char *line)
{
	int command_index = 0;
	char *commands, *parsed_command;
	char ***parsed_commands = malloc(MAX_CMDS * sizeof(char **));

	if (parsed_commands == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	commands = strtok(line, "|");
	while (commands != NULL && command_index < MAX_CMDS)
	{
		int arg_index = 0;
		char **command = malloc(MAX_ARGS * sizeof(char *));

		if (command == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		parsed_command = strtok(commands, TOK_DELIM);
		while (parsed_command != NULL && arg_index < MAX_ARGS - 1)
		{
			command[arg_index] = strdup(parsed_command);
			if (command[arg_index] == NULL)
			{
				fprintf(stderr, "Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
			arg_index++;
			parsed_command = strtok(NULL, TOK_DELIM);
		}
		command[arg_index] = NULL;
		parsed_commands[command_index] = command;
		command_index++;
		command = strtok(NULL, "|");
	}
	parsed_commands[command_index] = NULL;
	return (parsed_commands);
}
