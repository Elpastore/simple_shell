#include "shell.h"
/**
 * execute -function for executing commands
 * @tokens: array of tokens
 * @argv: array of argument
 * @env: environmen
 * Return: 0 if success.
 */
int execute(char **tokens, char **argv, char **env, int number)
{
	pid_t child_pid;
	int status;
	char *enter_command;

	(void)argv;
	
	enter_command = get_path(tokens[0]);

	if ((strcmp(tokens[0], "env") == 0))
	{
		my_env(env);

		free(enter_command), enter_command = NULL;
		free_array(tokens);
		return (1);
	}

	if (my_exit(tokens[0]))
	{
		
		free(enter_command), enter_command = NULL;
		free_array(tokens);
		exit(0);
	}
	if (enter_command == NULL)
	{
		/*empty command was entered*/
		erro_mess(argv[0], tokens[0], number);
		free_array(tokens);
		free(enter_command), enter_command = NULL;
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
