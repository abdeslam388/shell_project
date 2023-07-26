#include "shell.h"

/**
 * input_buf - buffers commande enchainee
 * @buf: addr de buffer
 * @info:  struct
 * @len: addr of len variable
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t s = 0;
	size_t len_p = 0;

	if (!*len) /* s'il n y a aucun , remplis le */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		s = getline(buf, &len_p, stdin);
#else
		s = _getline(info, buf, &len_p);
#endif
		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0'; /* eliminez les neauveux lignes */
				s--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* si (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = s;
				info->cmd_buf = buf;
			}
		}
	}
	return (s);
}

/**
 * get_input - avoir une ligne minus
 * @info:  struct
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* we have commands left into the  buffer */
	{
		j = i; /* new iterator to current buffer pos */
		p = buf + i; /* avoir un pointeur en retoure*/

		check_chain(info, buf, &j, i, len);
		while (j < len) /* semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /*  nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset  */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* back pointer to current command */
		return (_strlen(p)); /* retournez la lamguere de */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - lire un buffer
 * @info: struct
 * @buf: buffer
 * @s: size
 */
ssize_t read_buf(info_t *info, char *buf, size_t *s)
{
	ssize_t r = 0;

	if (*s)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*s = r;
	return (r);
}

/**
 * _getline - avoir la ligne prochaine de STDIN
 * @info: struct
 * @ptr: addr de ointeur
 * @length: lenght o fbuffer
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * siginHandler - blocks ctrl-C
 * @sig_num:nombre signal
 *
 * Return: void
 */
void siginHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
