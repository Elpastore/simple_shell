#include "shell.h"
/**
 * _split - function that split a given input
 * @input: string to be tokenize
 * Return: an array of pointer store the tokens
 */
char **_split(char *input)
{
	int count = 0;
	int numb_tok = 0;
	char *token = NULL;
	char **tokens = NULL;
	char *cp_input = NULL;

	if (input == NULL)
	{
		return (NULL);
	}
	cp_input = _strdup(input);
	token = strtok(cp_input, " \t\r\n\a\"");
	if (token == NULL)
	{
		free(input), input =  NULL;
		free(cp_input), cp_input = NULL;
		return (NULL);
	}
	while (token != NULL)
	{
		numb_tok++;
		token = strtok(NULL, " \t\r\n\a\"");
	}
	tokens = malloc((sizeof(char *) * (numb_tok + 1)));
	if (tokens == NULL)
	{
		free(input), input = NULL;
		return (NULL);
	}

	token = strtok(input, " \t\r\n\a\"");
	while (token != NULL)
	{
		tokens[count++] = _strdup(token);
		token = strtok(NULL, " \t\r\n\a\""); /*get the next token*/
	}
	tokens[count] = NULL;
	free(input), input = NULL;
	free(cp_input), cp_input = NULL;
	return (tokens);
}
