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
	char *prompt_shell = "#cisfun$ ";
	int len = _strlen(prompt_shell);


	while (1)
	{
		write(STDOUT_FILENO, prompt_shell, len);
		line = prompt();
		if (line == NULL)
		{
			/*EOF(Ctrl + D) was dectected*/
			write(STDOUT_FILENO, "\n", 1);
			free(line);
		}
		tokens =  _split(line);
		if (tokens == NULL)
			continue;
		execute(tokens, argv, env);
		/*let's free each element of array*/
		/*free the array itself*/

		/*command[0] = line;*/
		/*execute(command);*/
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

	if (isatty(STDIN_FILENO) == 1) /*check if we are in interactive mode*/
	{
		interactive_mode(argv, env);
	}
	else
	{
		while (1)
		{
			/*line = non_interactive();*/
			line = prompt();
			if (line == NULL)
			{
				write(STDOUT_FILENO, "\n", 1);
				free(line), line = NULL;
				exit(0);
			}
			tokens = _split(line);
			if (tokens == NULL)
				continue;
			execute(tokens, argv, env);
		}
	}
	return (0);
}
