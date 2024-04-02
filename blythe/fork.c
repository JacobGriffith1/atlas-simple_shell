#include "shell.h"
/**
 * fork - fork the process to execute a command.
 * @command: the command to execute.
 * @env: the enironment where to find the command function.
 * Return: NULL.
 */

void fork_exec(char **command, char *full_path)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command[0], command, full_path) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
