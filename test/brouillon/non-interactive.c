#include "shell.h"

/**
 * non_interactive - read a line from the stream
 *
 * Return: pointer that points to the read line
 */
char *non_interactive()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		nread  = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			return (NULL);
		}

    /*Remove newline character if present*/
		if (nread > 0 && line[nread - 1] == '\n')
		{
			line[nread - 1] = '\0';
		}
		return (line);
	}
}
