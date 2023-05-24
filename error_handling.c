#include "shell.h"

/**
 *_eputs - this is used to print an input string
 * @str: this shows the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int h = 0;

	if (!str)
		return;
	while (str[h] != '\0')
	{
		_eputchar(str[h]);
		h++;
	}
}

/**
 * _eputchar - this writes the character c to stderr
 * @c: Shows the character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(2, buf, h);
		h = 0;
	}
	if (c != BUF_FLUSH)
		buf[h++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int h;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || h >= WRITE_BUF_SIZE)
	{
		write(fd, buf, h);
		h = 0;
	}
	if (c != BUF_FLUSH)
		buf[h++] = c;
	return (1);
}

/**
 *_putsfd - this prints an input string
 * @str: shows the string to be printed
 * @fd:  shows the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int h = 0;

	if (!str)
		return (0);
	while (*str)
	{
		h += _putfd(*str++, fd);
	}
	return (h);
}
