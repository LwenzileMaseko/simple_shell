#include "shell.h"

/**
 * print_error -it prints error messages.
 * @info: parameter and return info struct
 * @estr: string with specified error type
 * Return: if no numbers in string 0, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_puts(info->fname);
	_puts(": ");
	print_d(info->line_count, STDERR_FILENO);
	_puts(": ");
	_puts(info->argv[0]);
	_puts(": ");
	_puts(estr);
}

/**
 * convert_number - function that converts
 * @num: number.
 * @base: Base.
 * @flags: Argument flags
 *
 * Return: String
 */
char *convert_number(long int number, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long num = number;

	if (!(flags & CONVERT_UNSIGNED) && number < 0)
	{
		num = -number;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[num % base];
		num /= base;
	} while (num != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_d -  prints  decimal (integer) number with (base 10)
 * @input: input
 * @fd: filedescriptor to be written to
 *
 * Return: number of characters to print
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int y, c = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		c++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (y = 1000000000; y > 1; y /= 10)
	{
		if (_abs_ / y)
		{
			__putchar('0' + current / y);
			c++;
		}
		current %= y;
	}
	__putchar('0' + current);
	c++;

	return (c);
}

/**
 * _erratoi - changes string to integer
 * @s: string to convert
 * Return: if there are no numbers in string 0, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
	int y = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this main return 255? */
	for (y = 0;  s[y] != '\0'; y++)
	{
		if (s[y] >= '0' && s[y] <= '9')
		{
			result *= 10;
			result += (s[y] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * rm_comments -It replaces first instance of '#' with '\0'
 * @buf: address of string to be modified.
 *
 * Return:0 Always;
 */
void remove_comments(char *buf)
{
	int y;

	for (y = 0; buf[y] != '\0'; y++)
		if (buf[y] == '#' && (!y || buf[y - 1] == ' '))
		{
			buf[y] = '\0';
			break;
		}
}

