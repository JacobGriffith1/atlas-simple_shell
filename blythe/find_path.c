#include "shell.h"
/**
 * find_path - Processes parsed commands.
 * @cmds - Parsed commands to be processed
 * @env - The environment containing the PATH
 * Return: NULL.
 */

void find_path(char ***cmds, char **env)
{
	int command_index = 0;

	while (parsed_commands[command_index] != NULL)
	{
		char **command = parsed_commands[command_index];
        int is_builtin = 0;
		int i = 0;
	
		for (i = 0; i < MAX_BUILTINS; i++)
		{
			if (strcmp(command[0], builtins[i]) == 0)
			{
				execute_builtin(command);
				is_builtin = 1;
				break;
			}
		}
		if (!is_builtin)
		{
			char *path_env = getenv("PATH");
			char *path_copy = strdup(path_env);
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
				{
					pid_t pid = fork();

					if (pid == -1)
					{
						perror("Fork failed");
						exit(EXIT_FAILURE);
					}
					else if (pid == 0)
					{
						execve(full_path, command, env);
						perror("Execve failed");
						exit(EXIT_FAILURE);
                    }
					else
					{
						int status;

						waitpid(pid, &status, 0);
						break;
					}
				}
				free(full_path);
				path_dir = strtok(NULL, ":");
			}
			free(path_copy);
		}
		command_index++;
	}
}