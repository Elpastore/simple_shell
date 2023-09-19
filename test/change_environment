#include "shell.h"
/**
 * len_env: function that give the length of environment
 * Return: the length of it
 */
size_t len_env(void)
{
	char **env_ptr = environ;
	size_t len = 0;
	while (*env_ptr)
	{
		len++;
		env_ptr++;
	}
	return (len);
}
/**
 * my_setenv - function that set environment
 * @name: name of environment
 * @value: the value
 * @overwrite: of 0  dont overwrite otherwise do
 * Return: 0 if success or -1 if failed
 */
int my_setenv(char *name, char *value, int overwrite)
{
	char *env_var;
	char **envp = environ;
	char **new_environ, **new_env_ptr;
	int len_name = _strlen(name);
	int len_value = _strlen(value);
	int len_env_var = len_value + len_name + 2;
	int env_lenght = len_env();
	char *message_error = "Usage: setenv VARIABLE VALUE\n";

	if (name == NULL || value == NULL)
	{
		write(STDERR_FILENO, message_error, _strlen(message_error));
		return (-1);
	}

	env_var = malloc(len_env_var);
	if (env_var == NULL)
	{
		perror("malloc");
		return (-1);
	}
	_strcpy(env_var, name);
	_strcat(env_var, "=");
	_strcat(env_var, value);
	/* check if the env variable exist*/
	while(*envp != NULL)
	{
		if(strncmp(*envp, name, len_name) == 0)
		{
			if (!overwrite)/*The environment variable exist and don't overwrite*/
			{
				free(env_var);
				return (0);
			}
			*envp = env_var /*overwrite the existing value*/;
			return (0);
		}
	}
	envp++;

	new_environ = malloc(sizeof(char *) * (env_lenght + 2));
	if (*new_environ == NULL)
	{
		perror("malloc");
		free(env_var);
		return (-1);
	}
	/*copies the old env into new env*/
	new_env_ptr = new_environ;
	while (*envp != NULL)
	{
		*new_env_ptr = *envp;
		envp++;
		new_env_ptr++;
	}
	/* add the new env variable to the end of array*/
	*new_env_ptr = env_var;
	new_env_ptr++;
	*new_env_ptr = NULL;
	/*update the new environment*/
	/*free(environ);*/
	environ = new_environ;

	return (0);

}
/**
 * my_unsetenv -function remove an env variable
 * @name: the name of env variale to remove
 * Return: 0 if success or -1 if failed
 */
int my_unsetenv(char *name)
{
	char **envp = environ;
	char **new_environ;
	int env_length = len_env();
	char **new_env_ptr;
	char *error_1 = "Usage: unsetenv VARIABLE\n";
	char *error_2 = "unsetenv: ";
	char *error_3 = ": environment variable not found\n";

	if (name == NULL)
	{
		write(STDERR_FILENO, error_1, _strlen(error_1));
		return (-1);
	}
	/*allocate mem for the newlie update environment*/
	new_environ = malloc(sizeof(char *) * (env_length + 1));
	if (new_environ == NULL)
	{
		perror("malloc");
		return (-1);
	}
	new_env_ptr = new_environ;
	while(*envp != NULL)
	{
		if (strncmp(*envp, name, strlen(name)) != 0)
		{
			*new_env_ptr = *envp;
			new_env_ptr++;
		}
		envp++;
	}
	*new_env_ptr = NULL;
	if (envp == environ)
	{
		/*Variable not found*/
		write(STDERR_FILENO, error_2, _strlen(error_2));
		write(STDERR_FILENO, name, _strlen(name));
		write(STDERR_FILENO, error_3, _strlen(error_3));
		free(new_environ);
		return (-1);
	}
	/*free(environ);*/
	environ = new_environ;
	return (0);
}

