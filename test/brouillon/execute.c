#include "shell.h"
/**
 * execute -function for executing commands
 * @tokens: array of tokens
 * @argv: array of argument
 * @env: environmen
 * Return: 0 if success.
 */
int execute(char **tokens, char **argv)
{
	pid_t child_pid;
	int status;

	if (tokens[0] == NULL)
	{
		return (1);
		/* empty command was entered */
	}
	/* Create a loop to execute 5 times a child process*/
	else
	{
		child_pid = fork(); /* Here we create a child process*/
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0) /*Here we execute command*/
		{
			if ((execve(tokens[0], tokens, environ) == -1))
			{
				perror(argv[0]);
				free_array(tokens);
				exit(EXIT_FAILURE);
			}
		}
		else /*Herre we are waiting for child process*/
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(EXIT_FAILURE);
			}
			free_array(tokens);
		}
	}
	/*return (status);*/
	return (WEXITSTATUS(status));
}
