#include "shell.h"

/**
 * its_delim - makes sure if characters are a delimeter
 * @k: a char to be check
 * @delim: delimeter string
 * Return:shows 1 if true, 0 if false
 */
int its_delim(char k, char *delim)
{
	while (*delim)
		if (*delim++ == k)
			return (1);
	return (0);
}

/**
 * interactive_mode - shows true if shell is in interactive mode
 * @info: struct address
 *
 * Return:shows 1 if interactive mode, 0 otherwise
 */
int interactive_mode(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _alpha - makes sure alphabetic character are checked
 * @k: character to be inputed
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _alpha(int k)
{
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoic - changes string to integer
 * @s: strings that will be converted
 * Return:shows 0 if no numbers are in the string, converted number otherwise
 */

int _atoic(char *s)
{
	int k, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (k = 0; s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
			sign *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[k] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

