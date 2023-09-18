#include "shell.h"
/**
 * execute -function for executing commands
 * @tokens: array of tokens
 * @argv: array of argument
 * @env: environmen
 * Return: 0 if success.
 */
int execute(char **tokens, char **argv, char **env)
{
	pid_t child_pid;
	int status;
	char *command = get_path(tokens[0]);
	/*char *actual_command = NULL;*/

	if (tokens[0] == NULL)
	{
		/* empty command was entered */
		return (1);
	}
	/* Create a loop to execute 5 times a child process*/
	else
	{
		/*actual_command = get_path( tokens[0]);*/
		child_pid = fork(); /* Here we create a child process*/
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(EXIT_FAILURE);

		}
		if (child_pid == 0) /*Here we execute command*/
		{
			if ((execve(command, tokens, env) == -1))
			{
				perror(argv[0]);
				/*free(actual_command),actual_command = NULL;*/
				free_array(tokens);
				free(command);
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

			/*free(actual_command), actual_command = NULL;*/
		}
	}

	/*return (status);*/
	return (0);
}