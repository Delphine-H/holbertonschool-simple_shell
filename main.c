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

	while (should_continue)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}

		bytes_read = getline(&buffer, &buffer_size, stdin);
		if (bytes_read == -1)
		{
			should_continue = 0;
			break;
		}
		else
		{
			array_tokens = _get_token(buffer);
			if (array_tokens[0] == NULL)
			{
				free_tokens(array_tokens);
				continue;
			}

		if (strcmp(array_tokens[0], "exit") == 0)
			exit_shell(buffer, array_tokens);

		if (strcmp(array_tokens[0], "env") == 0)
			print_env();

		execute_command(array_tokens);
		free_tokens(array_tokens);
		}
	}
	free(buffer);
	return (0);
}
