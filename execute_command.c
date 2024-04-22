#include "main.h"

/**
 * execute_command - execute a command if it exists
 * @command: command to execute
 * @array_tokens: array of command and arguments
 *
 * Return: 1 on success, 0 on failure
 */

int execute_command(char *command, char **array_tokens)
{
	pid_t pid;
	int status; /* Variable to store child process status */

	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(command, array_tokens, NULL) == -1)
		{
			perror("Error ");
			free_tokens(array_tokens);
			return (0);
		}
	}
	else if (pid < 0)
	{
		perror("Fork failed ");
		free_tokens(array_tokens);
		exit(EXIT_FAILURE);
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0); /* Wait for child to finish */
		if (status == EXIT_SUCCESS) /* Check if terminated normally */
		{
			free_tokens(array_tokens);/* Free tokens in the parent process*/
		}
		return (1);
	}

	return (0);
}
