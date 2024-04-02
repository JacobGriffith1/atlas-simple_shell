#include "shell.h"

void find_env(char ***cmds)
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
			fork_exec(command, full_path);
		free(full_path);
		path_dir = strtok(NULL, ":");
	}
	free(path_copy);
}
