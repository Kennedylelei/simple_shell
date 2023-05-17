#include "shell.h"

/**
 * _strlen - this returns the length of a string
 * @s: shows the string whose length to check
 *
 * Return: shows the integer length of string
 */
int _strlen(char *s)
{
	int p = 0;

	if (!s)
		return (0);

	while (*s++)
		p++;
	return (p);
}

/**
 * _strcmp - this performs the alphabetical order comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - this checks if needle starts with haystack
 * @haystack: shows the string to search
 * @needle: the substring to find
 *
 * Return:  shows the address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - this concatenates two strings
 * @dest: shows the destination buffer
 * @src: shows the source buffer
 *
 * Return: shows pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
