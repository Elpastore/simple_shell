#include "shell.h"

int execute(char **tokens, char **argv, char **env)
{
	pid_t child_pid;
	int status;
	/**int numb_process = 5;
	 * char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	 */

	if (tokens[0] == NULL)
	{
  	/* empty command was entered */
  		return (-1);
	}
	/* Create a loop to execute 5 times a child process*/
	else
	{
		child_pid = fork(); /* Here we create a child process*/
		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}
		if (child_pid == 0) /*Here we execute command*/
		{
			if ((execve(tokens[0], tokens, env) == -1))
			{
				perror(argv[0]);
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

			if (WIFEXITED(status))
			{
				/*printf("Child exited with status: %d\n", WEXITSTATUS(status));*/
			}
			else
			{
				printf("Child did not exit normally.\n");
			}
		}
	}
	/*return (status);*/
	return (0);
}
