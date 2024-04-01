#include "shell.h"
/**
 * fork - fork the process to execute a command.
 * @command - the command to execute.
 * @env - the enironment where to find the command function.
 * Return - NULL.
 */

void fork(char **command, char **env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(command[0], command, env);
		perror("Execve failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		waitpid(pid, &status, 0);
	}
}
