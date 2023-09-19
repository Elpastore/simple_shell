#include "shell.h"
/**
 * my_cd -function that change directory
 * @tokens: input
 */
void my_cd(char **tokens)
{
	if (tokens[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(tokens[1]) != 0)
		{
			perror("chdir");
		}
	}
}
