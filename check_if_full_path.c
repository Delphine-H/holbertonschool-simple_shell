#include "main.h"

/**
 * check_if_full_path - function that check if command is full path
 * @command: command to check
 * Return: 1 if success, 0 failure
*/

int check_if_full_path(char **array_tokens)
{
	char *command_path;

	if (access(array_tokens[0], X_OK) == 0)
	{
		/*printf("avant execution");*/
		execute_command(array_tokens[0], array_tokens);
		/*printf("command executable");*/
	}
	else
	{
		command_path = get_command_path(array_tokens[0]);
		if (command_path)
		{
			/*printf("command trouvée");*/
			
			if (!execute_command(command_path, array_tokens))
				printf("Command failed: %s\n", array_tokens[0]);

		free(command_path);
		}
		else
		{
		printf("Command not found: %s\n", array_tokens[0]);
		}
	}

	return (0);
}
