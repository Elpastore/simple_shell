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
	char *enter_command;
	
	(void)argv;

	if (my_exit(tokens[0]))
	{
		free_array(tokens);
		exit(0);
	}
	enter_command = get_path(tokens[0]);
	if (enter_command == NULL)
	{
		/*empty command was entered*/
		write(STDERR_FILENO,argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDERR_FILENO, ": ", 2);
		erro_mess();
		write(STDERR_FILENO, "\n", 1);
		free_array(tokens);
		return (1);
	}
	/* Create a loop to execute 5 times a child process*/
	else
	{
		child_pid = fork(); /* Here we create a child process*/
		if (child_pid == -1)
		{
			perror("Error: ");
			exit(127);
		}
		if (child_pid == 0) /*Here we execute command*/
		{
			if ((execve(enter_command, tokens, env) == -1))
			{
				perror("execve");
				free(enter_command), enter_command = NULL;
				free_array(tokens);
				exit(127);
			}
		}
		else /*Herre we are waiting for child process*/
		{
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("waitpid");
				exit(127);
			}

			free(enter_command), enter_command =NULL;
			free_array(tokens);
		}
	}

	/*return (status);*/
	return (0);
}
