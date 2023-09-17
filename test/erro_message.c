#include "shell.h"
void erro_mess(char *name, char *input, int number)
{
	char *convert = convert_number(number);/*allocated memory from convert_number*/
	char *message = ": not found\n";
	int len_message = _strlen(message);

	write(STDERR_FILENO,name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, convert, _strlen(convert));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, message, len_message);
	write(STDERR_FILENO, "\n", 1);

	free(convert);
}
