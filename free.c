#include "main.h"

/**
 * free_tokens - function that free an array of tokens
 * @array_tokens: array to free
*/

void free_tokens(char **array_tokens)
{
	int index = 0;

	while (array_tokens[index] != NULL)
	{
		free(array_tokens[index]);
		index++;
	}
	free(array_tokens);
}
