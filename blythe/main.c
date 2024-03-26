#include "shell.h"
/**
 * main - Simple shell
 * @argc: Arg count
 * @argv: Arg vector
 * @env: Enviornment variable
 * Return: 0 or -1 on fail.
 */

int main(int argc, char **argv, char **env)
{
	while (1)
	{
		cmds = prompt();
		find_path(cmds);
	}
	return (0);
}
