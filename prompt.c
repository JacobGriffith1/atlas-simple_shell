#include "shell.h"
/**
 * prompt - Prompts and parses user input.
 *
 * Return: Parsed user input.
 */

char **prompt()
{
	char *line;
	char **parsed_cmds;

	printf(":) ");
	line = getline();
	parsed_cmds = parse(line);

	free(line);

	return (parsed_cmds);
}
