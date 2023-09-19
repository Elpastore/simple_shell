#include "shell.h"
/**
 * my_exit -function that exit program
 * @input: command enter by user
 * Return: 0
 */
int my_exit(char *input)
{
	return (_strcmp(input, "exit") == 0);
}
