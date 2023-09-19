#include "shell.h"
/**
 * erro_mess - fucntion that print message error
 * @name: name of program
 * @input: command enter by the user
 * @number: number of executed command
 */
void erro_mess(char *name, char *input, int number)
{
	char *convert = convert_number(number);/**allocated memory
						* from convert_number
						*/

	char *message = ": not found";
	int len_message = _strlen(message);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, convert, _strlen(convert));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, message, len_message);
	write(STDERR_FILENO, "\n", 1);

	free(convert);
}
