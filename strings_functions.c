#include "shell.h"

/**
 * *_strcat - concatenates @src to @dest
 * @src: the source string to append to @dest
 * @dest: the destiation string to be concatenated upon
 * Return:pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int index = 0;
	int dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index]; index++)
		dest[dest_len++] = src[index];
	dest[dest_len] = '\0';
	return (dest);
}
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
/**
 * _strcpy - main function to copy
 *
 * @dest: destination to copy
 * @src: src
 *
 * Return: a character value
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = _strlen(src);

	for (i = 0; i <= len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _strlen - gets character string
 *
 * @s: character to getstring
 * Return: returns length
 */
int _strlen(char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; len++)
	{
	}
	return (len);
}
