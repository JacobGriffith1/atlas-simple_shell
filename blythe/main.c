#include "shell.h"
/**
 * main - Simple shell
 * @argc: Arg count
 * @argv: Arg vector
 * @env: Enviornment variable
 * Return: 0 or -1 on fail.
 */

int main(void)
{
	while (1)
	{
		char ***cmds = **prompt();

		find_path(cmds);
	}
	return (0);
}
