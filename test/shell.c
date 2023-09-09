#include "shell.h"
void sigint_handler()
{
}

/**
 * main -my own shell program
 * Return: 0 if success, otherwise -1
 */
int main(int argc __attribute((unused)),char **argv)
{

	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int i;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (1)
		{
			printf("#cisfun$ ");
			if (signal(SIGINT, sigint_handler) == SIG_ERR)
			{
				perror("signal");
				exit(EXIT_FAILURE);
			}

			line = prompt();
			if (line == NULL)
			{
				/*EOF(Ctrl + D) was dectected*/
				printf("\n");
				free(line);
				exit(EXIT_SUCCESS);
			}
			tokens =  _split(line);
			execute(tokens, argv);
			/*let's free each element of array*/
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			/*free the array itself*/
			free(tokens);

			/*command[0] = line;*/
			/*execute(command);*/
			free(line);
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
			execute(tokens, argv);
			/*let's free each element of array*/
			for (i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			/*free the array itself*/
			free(tokens);
			free(line);
		}
	}
	free(line);
	return (0);
}
