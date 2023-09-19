#include "shell.h"

 /**
 * _putsfd - print input string
 * @str:  string to print
 * @fd: filedescriptor to write to
 *
 * Return: number of chars put
 */
int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}

/**
 * _eputchar - writes character c to a stderr
 * @c: character to be printed
 *
 * Return:1 on success
 * On error, -1 will returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _putfd - writes character c to given fd
 * @c:  character to be printed
 * @fd: filedescriptor to write to
 *
 * Return:1 On success
 * On error, -1 will be returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}

/**
 * _eputs - print the input string
 * @str: string to print
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}


