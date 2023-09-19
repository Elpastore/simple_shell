#include "shell.h"
/**
 * _getenv - function to  get the environmeent  variable
 * @va_env: name if environment
 * Return: pointer to the specific env  or NUL
 */
char *_getenv(char *va_env)
{
	char *token;
	char *next;
	char *env;
	char *temp;
	int i;

	for (i =  0; environ[i] != NULL;  i++)
	{
		temp = _strdup(environ[i]);
		token = strtok(temp, "=");
		if (strcmp(token, va_env) == 0)/*search for env variable*/
		{
			next = strtok(NULL, "\n");/**pass to the next environment
						    * separe by the previous by \n
						    */
			env = _strdup(next);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
