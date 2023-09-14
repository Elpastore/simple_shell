#include "shell.h"
/**
 * get_path - function that check for path of command
 * @command: the entry command
 * Return: a pointer of the full path
 */
char *get_path(char *tokens)
{
	char *path = _getenv("PATH");
	char *token;
	/*char *cp_path;*/
	int len_tokens, len_dir;
	char *full_path;
	struct stat st;
	/*cp_path = strdup(path);*/

	if(stat(tokens, &st) == 0)
	{
		return (_strdup(tokens));
	}
	token = strtok(path, ":");
	while(token != NULL)
	{


		len_tokens = _strlen(tokens);
		len_dir = _strlen(token);
		full_path = malloc(len_tokens + len_dir + 2);
		if (full_path != NULL)
		{
			_strcpy(full_path, token);
			_strcat(full_path, "/");
			_strcat(full_path, tokens);

			if (stat(full_path, &st) == 0)
			{
				free(path);
				return (full_path);
			}
			free(full_path), full_path = NULL;
			token = strtok(NULL, ":");
		}
	}
	free(path);

	return (NULL);
}
