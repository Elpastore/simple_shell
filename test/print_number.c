#include "shell.h"
/**
 * convert_number - function that convert an interger to a string
 * @num: number to be converted
 * Return: the string containing th convert result
 */
char *convert_number(int num)
{
	char buffer[20];
	int len = 0;
	int i;
	char *reverse;

	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}

	do {
		buffer[len++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	buffer[len] = '\0';

    /* Reverse the string*/
	reverse = malloc(sizeof(char) * (len + 1));
	if (reverse == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < len; i++)
	{
		reverse[i] = buffer[len - i - 1];
	}
	reverse[len] = '\0';
	return (reverse);
}
