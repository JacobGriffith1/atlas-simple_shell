#include "shell.h"
/**
 * find_path - Processes parsed commands.
 * @cmds: Parsed commands to be processed
 * @env: The environment containing the PATH
 * Return: NULL.
 */

void find_path(char ***cmds, char **env)
{
	int cmnd_i = 0;

	while (cmds[cmnd_i] != NULL)
	{
		char **command = cmds[cmnd_i];
		int is_builtin = 0, i = 0;

		for (i = 0; i < MAX_BUILTINS; i++)
			if (strcmp(command[0], builtins[i]) == 0)
			{
				num_builtins(command);
				is_builtin = 1;
				break;
			}
		if (!is_builtin)
		{
			char *path_env = getenv("PATH"), *path_copy = strdup(path_env);
			char *path_dir = strtok(path_copy, ":");

			while (path_dir != NULL)
			{
				char *full_path = malloc(strlen(path_dir) + strlen(command[0]) + 2);

				if (full_path == NULL)
				{
					perror("Memory allocation failed");
					exit(EXIT_FAILURE);
				}
				strcpy(full_path, path_dir);
				strcat(full_path, "/");
				strcat(full_path, command[0]);
				if (access(full_path, X_OK) == 0)
					fork_exec(command, env);
				free(full_path);
				path_dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		cmnd_i++;
	}
}
