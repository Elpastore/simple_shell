#include "shell.h"
#define READ_SIZE 1024

static char buffer[READ_SIZE];
static ssize_t buffer_index = 0;
static ssize_t buffer_size = 0;
/**
 * _getline - Custom getline function to read lines from a file descriptor.
 * @lineptr: Pointer to a buffer that will store the read line.
 * @n: Pointer to the size of the buffer.
 * @fd: The file descriptor to read from.
 *
 * Return: The number of characters read, including the newline character,
 * or -1 on error.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	size_t totalBytesRead = 0;
	int newlineFound = 0;
	char c;
	char *newLine;
	char *line = *lineptr;

	if (lineptr == NULL || n == NULL || fd < 0)
	{
		return (-1); /*Invalid input parameters*/
	}
	/*ssize_t bytesRead = 0;*/
	if (*n == 0 || line == NULL)
	{
		/*Initialize or allocate memory for line*/
		*n = 1024; /*Default buffer size*/
		line = (char *)malloc(*n);
		if (line == NULL)
		{
			return (-1); /*Memory allocation failed*/
		}
		*lineptr = line;
	}
	while (1)
	{
        /*Check if the buffer needs to be refilled*/
		if (buffer_index >= buffer_size)
		{
			buffer_size = read(fd, buffer, 1024); /*Read in chunks of 1024 bytes*/
			if (buffer_size <= 0)
			{
				/*End of file or error*/
				if (totalBytesRead == 0)
				{
					/*free(line);*/
					write(STDOUT_FILENO, "\n", 1);
					return (-1); /*No data read*/
				}
				break;
			}
			buffer_index = 0;
		}
		/*Copy bytes from buffer to line*/
		while (buffer_index < buffer_size)
		{
			c = buffer[buffer_index++];
			if (c == '\n')
			{
				newlineFound = 1;
				break;
			}
			if (totalBytesRead >= *n - 1)
			{
				/*Resize the line buffer if needed*/
				*n *= 2;
				newLine = (char *)realloc(line, *n);
				if (newLine == NULL)
				{
					free(line);
					return (-1); /*Memory reallocation failed*/
				}
				line = newLine;
				*lineptr = line;
			}
			line[totalBytesRead++] = c;
		}
		if (newlineFound)
		{
			break;
		}
	}
	/*Null-terminate the line*/
	line[totalBytesRead] = '\0';
	return (totalBytesRead);
}
