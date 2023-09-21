#include "shell.h"

/**
 **_strncat - joins two strings.
 *@dest: first string
 *@src: second string
 *@n: amount of bytes that will be maximally used
 *Return: strings to be concatenated
 */
char *_strncat(char *dest, char *src, int n)
{
	int w, y;
	char *s = dest;

	w = 0;
	y = 0;
	while (dest[w] != '\0')
		w++;
	while (src[y] != '\0' && y < n)
	{
		dest[w] = src[y];
		w++;
		y++;
	}
	if (y < n)
		dest[w] = '\0';
	return (s);
}

/**
 **_strchr - shows a character in a string
 *@s: string that will be parsed
 *@car: character to look for
 *Return: (s) pointer to memory area
 */
char *_strchr(char *s, char car)
{
	do {
		if (*s == car)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncpy - duplicates a string
 *@dest: destination the string to be copied to
 *@src: source string
 *@num:  amount of characters that will be copied
 *Return:  concatenated string
 */
char *_strncpy(char *dest, char *src, int num)
{
	int w, y;
	char *s = dest;

	w = 0;
	while (src[w] != '\0' && w < num - 1)
	{
		dest[w] = src[w];
		w++;
	}
	if (w < num)
	{
		y = w;
		while (y < num)
		{
			dest[y] = '\0';
			y++;
		}
	}
	return (s);
}

