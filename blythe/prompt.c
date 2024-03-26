#include "shell.h"
/**
 * prompt - Prompts and parses user input.
 *
 * Return: Parsed user input.
 */

char **prompt()
{
	char *line = NULL;
	char **parsed_cmds;
	ssize_t line_length;
	size_t bufsize = 0;

	printf(":) ");
	line_length = getline(&line, &bufsize, stdin);
	if (line_length == -1)
	{
		perror("getline failed");
		exit(EXIT_FAILURE);
	}
	parsed_cmds = *parse(line);
	free(line);

	return (parsed_cmds);
}
