#include "shell.h"
/**
 * _strdup - duplicate a string and allocate the same memory
 * @str: string to be duplicated
 * Return: a pointer
 */
char *_strdup(char *str)
{

	char *p;
	int len_str, i;

	if (str == NULL)
	{
		return (NULL);
	}

	len_str = _strlen(str) + 1;
	p = malloc(sizeof(char) * len_str);

	if (p == NULL)
	{
		return (NULL);
	}

	for (i =  0; i < len_str; i++)
	{
		p[i] = str[i];
	}

	return (p);
}
