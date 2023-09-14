#include "shell.h"
void erro_mess(void)
{
	char *message = "not found\n";
	int len_message = _strlen(message);

	write(STDERR_FILENO, message, len_message);

}
