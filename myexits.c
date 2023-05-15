#include "shell.h"

/**
 **_strncpy - used to copy a string
 *@dest: the destination where a string is to be copied to
 *@src: the source sring
 *@n: total amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int q, p;
	char *s = dest;

	q = 0;
	while (src[q] != '\0' && q < n - 1)
	{
		dest[q] = src[q];
		q++;
	}
	if (q < n)
	{
		p = q;
		while (p < n)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings with a specific length
 *@dest: the first string/the destination string
 *@src: the second string to append
 *@n: the total amount of bytes/characters to be used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int q, p;
	char *s = dest;

	q = 0;
	p = 0;
	while (dest[q] != '\0')
		q++;
	while (src[p] != '\0' && p < n)
	{
		dest[q] = src[p];
		q++;
		p++;
	}
	if (p < n)
		dest[q] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be searched
 *@c: the character to be looked for
 *Return: (s) a pointer to the memory area s,
 *            or NULL if character is not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
