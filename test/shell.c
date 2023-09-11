#include "shell.h"

/**
 * interactive_mode - shell interaction mode
 * @argv: array of argument
 * @env: the environment
 */
void interactive_mode(char **argv, char **env)
{
	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int i;


	while (1)
	{
		printf("#cisfun$ ");
		line = prompt();
		if (line == NULL)
		{
			/*EOF(Ctrl + D) was dectected*/
			printf("\n");
			free(line);
			exit(EXIT_SUCCESS);
		}
		tokens =  _split(line);
		execute(tokens, argv, env);
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

/**
 * main -my own shell program
 * @argc: number of argument
 * @argv: array of argumemnt
 * @env: environment
 * Return: 0 if success, otherwise -1
 */
int main(int argc __attribute__((unused)), char **argv, char **env)
{

	char *line;
	/*char *command[] = {NULL, NULL};*/
	char **tokens;
	int i;

	if (isatty(STDIN_FILENO) == 1) /*check if we are in interactive mode*/
	{
		interactive_mode(argv, env);
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
			execute(tokens, argv, env);
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
	return (0);
}
