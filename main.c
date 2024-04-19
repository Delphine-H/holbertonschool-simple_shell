#include "main.h"

/**
 * main - program of our custom shell who is a command-line interface
 * used to interact with an operating system,
 * allowing users to execute commands, and run scripts.
 *
 * Return: (0) success
*/

int main(void)
{
	char *buffer = NULL; /* Buffer for getline */
	size_t buffer_size = 0;
	ssize_t bytes_read = 0; /* number of bytes read */
	int should_continue = 1;
	char **array_tokens;
	pid_t pid;
	int status;

	while (should_continue)
	{
		printf("$ ");
		bytes_read = getline(&buffer, &buffer_size, stdin);
		if (bytes_read == -1)
		{
			should_continue = 0;
		}
		else
		{
			array_tokens = _get_token(buffer);
			if (array_tokens[0] == NULL)
			{
				printf("No tokens found.\n");
				free_tokens(array_tokens);
				return (EXIT_FAILURE);
			}

			pid = fork();
			if (pid == 0) /* Child process */
			{
				if (execve(array_tokens[0], array_tokens, NULL) == -1)
				{
					perror("Error ");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid < 0)
			{
				perror("Fork failed ");
				free_tokens(array_tokens);
				free(buffer);
				exit(EXIT_FAILURE);
			}
			else /* Parent process */
			{
				waitpid(pid, &status, 0); /* Wait for child to finish */
				free_tokens(array_tokens);
			}
		}
	}

	free(buffer);

	return (0);
}
