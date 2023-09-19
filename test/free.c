#include "shell.h"
/**
 * free_array - function that free arrya
 * @tokens: array to be freed
 */
void free_array(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;
	/*let's free each element of array*/
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]), tokens[i] = NULL;
	}
	/*free the array itself*/
	free(tokens), tokens = NULL;

}
