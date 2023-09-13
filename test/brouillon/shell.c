#include "shell.h"


/**
 * main -my own shell program
 * @argc: number of argument
 * @argv: array of argumemnt
 * @env: environment
 * Return: 0 if success, otherwise -1
 */
int main(int argc __attribute__((unused)), char **argv)
{

	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int status= 0;

	if (isatty(STDIN_FILENO) == 1) /*check if we are in interactive mode*/
	{
		while (1)
		{
			printf("#cisfun$ ");
			line = prompt();
			if (line == NULL)
			{
				/*EOF(Ctrl + D) was dectected*/
				printf("\n");
				free(line);
				return (status);
			}
			tokens =  _split(line);
			if (tokens == NULL)
				continue;

			status = execute(tokens, argv);
			/*command[0] = line;*/
			/*execute(command);*/
		}		
	}
	else
	{
		while (1)
		{
			line = non_interactive();
			if (line == NULL)
			{
				printf("\n");
				free(line);
				exit(EXIT_SUCCESS);
			}
			tokens = _split(line);
			status = execute(tokens, argv);
		}
	}
	return (0);
}

