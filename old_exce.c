#include "shell.h"
/**
 * execute -function for executing commands
 * @tokens: array of tokens
 * @argv: array of argument
 * @env: environment
 * @number: number of executed command
 * Return: 0 if success.
 */
int execute(char **tokens, char **argv, char **env, int number)
{
/**
 * struct builtin - structure for buidin command
 */
	struct builtin commands[] = {
		{"cd", my_cd},
		{NULL, NULL}
	};


	pid_t child_pid;
	int status;
	char *enter_command;
	int exit_status;
	int i;

	(void)argv;

	enter_command = get_path(tokens[0]);

	for (i = 0; commands[i].name != NULL; i++)
	{
		if (_strcmp(tokens[0], commands[i].name) == 0)
		{
			commands[i].f(tokens);
			free(enter_command), enter_command = NULL;
			free_array(tokens);
			return (1);
		}
	}
	if ((_strcmp(tokens[0], "env") == 0))
	{
		my_env(env);

		free(enter_command), enter_command = NULL;
		free_array(tokens);
		return (1);
	}

	if (my_exit(tokens[0]))
	{
		/*exit with if an argument*/
		if (tokens[1] != NULL)
		{
			exit_status = atoi(tokens[1]);
			free(enter_command), enter_command = NULL;
			free_array(tokens);
			/*exit(EXIT_SUCCESS);*/
			exit(exit_status);
		}
		else
		{
			free_array(tokens);
			exit(EXIT_SUCCESS);
		}
	}

	if (enter_command == NULL)
	{
		/*empty command was entered*/
		erro_mess(argv[0], tokens[0], number);
		free_array(tokens);
		free(enter_command), enter_command = NULL;
		/*exit(2);*/
		/*exit(EXIT_SUCCESS);*/
		return (1);
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
			if ((execve(enter_command, tokens, env) == -1))
			{
				perror("execve");
				free(enter_command), enter_command = NULL;
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

			free(enter_command), enter_command = NULL;
			free_array(tokens);
/**			if (WIFEXITED(status))
*			{
*				Set exit status based on the child process exit status
*				exit(WEXITSTATUS(status));
*			}
*			else
*			{
*				Handle error case if waitpid didn't return an exit status
*				Set exit status to 2 for error
*				exit(2);
*			}
*/		}
		/*return (status);*/
		return (0);
	}
}
