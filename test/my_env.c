#include "shell.h"
/**
 * my_env - function that print environment
 * @env: environment
 */
void my_env(char **env)
{
	int i;
	for (i = 0; env[i] != NULL; i++)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * my_exit: function that exit program
 * @env: environment
 *
 * void my_exit(char **env)
 * {
 * exit(0);
 * }
 */

