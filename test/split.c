#include "shell.h"
/**
 * _split - function that split a given input
 * @input: string to be tokenize
 * Return: an array of pointer store the tokens
 */
char **_split(char *input)
{
	/*int i = 0;*/
	int count = 0;
	int numb_tok = 0;
	char *token;
	char **tokens;
	char *cp_input = strdup(input);

	token = strtok(cp_input, " \t\n");
	while (token != NULL)
	{
		numb_tok++;
		token = strtok(NULL, " \t\n");
	}
	tokens = malloc((sizeof(char *) * (numb_tok + 1)));
	if (tokens == NULL)
	{
		return (NULL);
	}

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		tokens[count++] = strdup(token);
		token = strtok(NULL, " \t\n"); /*get the next token*/
	}
	tokens[count] = NULL;

	free(cp_input);
	return (tokens);
}
