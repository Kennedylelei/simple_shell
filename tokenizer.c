#include "shell.h"

/**
 * **strtow - Repeat delimiters are ignored and splits a string into words.
 * @str: the input string
 * @d: the delimeter string
 *
 * The delimiter string above uses the function to split the input into words.
 *
 * Return: a pointer to an array of strings, or NULL
 */

char **strtow(char *str, char *d)
{
	int a, b, c, k, numwords = 0;
	char **g;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], d) && (is_delim(str[a + 1], d) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	g = malloc((1 + numwords) * sizeof(char *));
	if (!g)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (is_delim(str[a], d))
			a++;
		c = 0;
		while (!is_delim(str[a + c], d) && str[a + c])
			c++;
		g[b] = malloc((c + 1) * sizeof(char));
		if (!g[b])
		{
			for (c = 0; c < k; c++)
				free(g[c]);
			free(g);
			return (NULL);
		}
		for (k = 0; k < c; k++)
			g[b][k] = str[a++];
		g[b][k] = 0;
	}
	g[b] = NULL;
	return (g);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, c, k, numwords = 0;
	char **g;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
		    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	g = malloc((1 + numwords) * sizeof(char *));
	if (!g)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		g[b] = malloc((c + 1) * sizeof(char));
		if (!g[b])
		{
			for (c = 0; c < b; c++)
				free(g[c]);
			free(g);
			return (NULL);
		}
		for (k = 0; k < c; k++)
			g[b][k] = str[a++];
		g[b][k] = 0;
	}
	g[b] = NULL;
	return (g);
}
