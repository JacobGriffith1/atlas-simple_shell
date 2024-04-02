#include "shell.h"

/**
 * find_path - Processes parsed commands.
 * @cmds: Parsed commands to be processed
 * @env: The environment containing the PATH
 * Return: NULL.
 */

void find_path(char ***cmds)
{
	int cmnd_i = 0;

	while (cmds[cmnd_i] != NULL)
	{
		char **command = cmds[cmnd_i];
		int is_builtin = 0, i = 0;
		char *builtins[] = {"cd", "exit", "help"};
		char *bicall[] = {&ss_cd, &ss_exit, &ss_help};

		for (i = 0; i < MAX_BUILTINS; i++)
			if (strcmp(command[0], builtins[i]) == 0)
			{
				is_builtin = 1;
				*bicall[i](command);
				break;
			}
		if (!is_builtin)
			find_env(cmds);
		cmnd_i++;
	}
}
