#include "shell.h"

/**
 * input_buf -  shows a buffers chained commands
 * @info: shows the parameter struct
 * @buf: shows the address of buffer
 * @len: shows the address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t q = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		q = getline(buf, &len_p, stdin);
#else
		q = _getline(info, buf, &len_p);
#endif
		if (q > 0)
		{
			if ((*buf)[q - 1] == '\n')
			{
				(*buf)[q - 1] = '\0';
				q--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
			*len = q;
			info->cmd_buf = buf;
			}
		}
	}
	return (q);
}

/**
 * get_input - this gets a line minus the newline
 * @info: shows the parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t a, b, len;
	ssize_t q = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	q = input_buf(info, &buf, &len);
	if (q == -1)
		return (-1);
	if (len)
	{
		b = a;
		p = buf + a;

		check_chain(info, buf, &b, a, len);
		while (b < len)
		{
			if (is_chain(info, buf, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (q);
}

/**
 * read_buf - this reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @a: size
 *
 * Return: q
 */
ssize_t read_buf(info_t *info, char *buf, size_t *a)
{
	ssize_t q = 0;

	if (*a)
		return (0);
	q = read(info->readfd, buf, READ_BUF_SIZE);
	if (q >= 0)
		*a = q;
	return (q);
}

/**
 * _getline - this gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr:  shows the address of pointer to buffer, preallocated or NULL
 * @length:  shows the size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, len;
	size_t c;
	ssize_t q = 0, s = 0;
	char *p = NULL, *new_p = NULL, *k;

	p = *ptr;
	if (p && length)
		s = *length;
	if (a == len)
		a = len = 0;

	q = read_buf(info, buf, &len);
	if (q == -1 || (q == 0 && len == 0))
		return (-1);

	k = _strchr(buf + a, '\n');
	c = k ? 1 + (unsigned int)(k - buf) : len;
	new_p = _realloc(p, s, s ? s + c : c + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + a, c - a);
	else
		_strncpy(new_p, buf + a, c - a + 1);

	s += c - a;
	a = c;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - used to block ctrl-C
 * @sig_num: this shows the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
