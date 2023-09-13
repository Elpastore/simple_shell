#include "shell.h"
/**
 * str_concat -concatenates two strings.
 * @s1: first string
 * @s2: second string
 * Return: a pointer
 */
char *str_concat(char *s1, char *s2)
{
	char *p;
	int i, len_s1, len_s2, len_p;
	int j = 0;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	len_s1 = _strlen(s1);
	len_s2 = _strlen(s2);
	len_p = len_s1 + len_s2 + 1;

	p = malloc(sizeof(char) * len_p);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len_s1; i++)
	{
		p[j++] = s1[i];
	}
	for (i = 0; i < len_s2; i++)
	{
		p[j++] = s2[i];
	}
	p[j++] = '\0';
	return (p);
}
