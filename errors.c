#include "shell.h"

 /**
 * _putffd - print input string
 * @str:  string to print
 * @fd: filedescriptor to write to
 *
 * Return: number of chars put
 */
int _putffd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putffd(*str++, fd);
	}
	return (k);
}

/**
 * eputchar - writes character c to a stderr
 * @y: character to be printed
 *
 * Return:1 on success
 * On error, -1 will returned, and errno is set appropriately.
 */
int eputchar(char y)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buf, k);
		k = 0;
	}
	if (y != BUF_FLUSH)
		buf[k++] = y;
	return (1);
}

/**
 * _putfd - writes character c to given fd
 * @y:  character to be printed
 * @fd: filedescriptor to write to
 *
 * Return:1 On success
 * On error, -1 will be returned, and errno is set appropriately.
 */
int _putfd(char y, int fd)
{
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (y == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buf, k);
		k = 0;
	}
	if (y != BUF_FLUSH)
		buf[k++] = y;
	return (1);
}

/**
 * _eput - print the input string
 * @str: string to print
 *
 * Return: Nothing
 */
void _eput(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		eputchar(str[k]);
		k++;
	}
}


