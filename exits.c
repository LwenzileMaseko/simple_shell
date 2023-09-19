#include "shell.h"

/**
 **_strncat - concatenates two strings.
 *@dest: first string
 *@src: second string
 *@n: amount of bytes that will be maximally used
 *Return: strings to be concatenated
 */
char *_strncat(char *dest, char *src, int n)
{
	int w, j;
	char *s = dest;

	w = 0;
	j = 0;
	while (dest[w] != '\0')
		w++;
	while (src[j] != '\0' && j < n)
	{
		dest[w] = src[j];
		w++;
		j++;
	}
	if (j < n)
		dest[w] = '\0';
	return (s);
}

/**
 **_strchr - shows a character in a string
 *@s: string that will be parsed
 *@c: character to look for
 *Return: (s) pointer to memory area
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncpy - duplicates a string
 *@dest: destination the string to be copied to
 *@src: source string
 *@n:  amount of characters that will be copied
 *Return:  concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int w, j;
	char *s = dest;

	w = 0;
	while (src[w] != '\0' && w < n - 1)
	{
		dest[w] = src[w];
		w++;
	}
	if (w < n)
	{
		j = w;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

