#include "shell.h"
/**
 * get_path - function that check for path of command
 * @command: the entry command
 * Return: a pointer of the full path
 */
char *get_path(char *tokens)
{
	char *path = getenv("PATH");
	char *token;
	char *cp_path;
	int len_tokens, len_dir;
	char *full_path;
	struct stat st;
	if (path != NULL)
	{
		cp_path = strdup(path);
		len_tokens = strlen(tokens);
		token = strtok(cp_path, ":");
		while(token != NULL)
		{
			len_dir = strlen(token);
			full_path = malloc(len_tokens + len_dir + 2);
			strcpy(full_path, token);
			strcat(full_path, "/");
			strcat(full_path, tokens);
			strcat(full_path, "\0");

			if (stat(full_path, &st) == 0)
			{
				free(cp_path);
				return (full_path);
			}
			else
			{
				free(full_path);
				token = strtok(NULL, ":");
			}
		}
		free(cp_path);
		if(stat(tokens, &st) == 0)
		{
			return (tokens);
		}
		return (NULL);
	}
	return (NULL);
}
