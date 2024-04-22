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
	/* char *command_path; */

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
				continue;
			}
		/* command_path = get_command_path(array_tokens[0]);
		if (command_path)
		{
			if (!execute_command(command_path, array_tokens))
				printf("Command failed: %s\n", array_tokens[0]);

			free(command_path);
		}
		else
		{
			printf("Command not found: %s\n", array_tokens[0]);
		}
		free_tokens(array_tokens); */
		}

		check_if_full_path(array_tokens);
		free_tokens(array_tokens);
	}
	free(buffer);
	return (0);
}
