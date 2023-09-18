#include "shell.h"
/**
 * prompt - function that allow to take command as  input
 * Return: the given input
 */
char *prompt(void)
{
	char *line =   NULL;
	size_t count = 0;
	ssize_t nread;

	nread = getline(&line, &count, stdin);
	if (nread == -1)
	{
		if (feof(stdin)) /*test for eof*/
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(line);
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	/* Delete new line char*/
	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}