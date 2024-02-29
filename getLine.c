#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @jojo: parameter struct
 * @dssjjjlghhj: address of buffer
 * @llelleelel: address of llelleelel var
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *jojo, char **dssjjjlghhj, size_t *llelleelel)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*llelleelel) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)jojo->cmd_buf);*/
		free(*dssjjjlghhj);
		*dssjjjlghhj = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(dssjjjlghhj, &len_p, stdin);
#else
		r = _getline(jojo, dssjjjlghhj, &len_p);
#endif
		if (r > 0)
		{
			if ((*dssjjjlghhj)[r - 1] == '\n')
			{
				(*dssjjjlghhj)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			jojo->linecount_flag = 1;
			remove_comments(*dssjjjlghhj);
			build_history_list(jojo, *dssjjjlghhj, jojo->histcount++);
			/* if (_strchr(*dssjjjlghhj, ';')) is this a command chain? */
			{
				*llelleelel = r;
				jojo->cmd_buf = dssjjjlghhj;
			}
		}
	}
	return (r);
}

/**
 * get_input - gets a line minus the newline
 * @jojo: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *jojo)
{
	static char *dssjjjlghhj; /* the ';' command chain buffer */
	static size_t deathnote, j, llelleelel;
	ssize_t r = 0;
	char **buf_p = &(jojo->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(jojo, &dssjjjlghhj, &llelleelel);
	if (r == -1) /* EOF */
		return (-1);
	if (llelleelel)	/* we have commands left in the chain buffer */
	{
		j = deathnote; /* init new iterator to current dssjjjlghhj position */
		p = dssjjjlghhj + deathnote; /* get pointer for return */

		check_chain(jojo, dssjjjlghhj, &j, deathnote, llelleelel);
		while (j < llelleelel) /* iterate to semicolon or end */
		{
			if (is_chain(jojo, dssjjjlghhj, &j))
				break;
			j++;
		}

		deathnote = j + 1; /* increment past nulled ';'' */
		if (deathnote >= llelleelel) /* reached end of buffer? */
		{
			deathnote = llelleelel = 0; /* reset position and length */
			jojo->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = dssjjjlghhj; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @jojo: parameter struct
 * @dssjjjlghhj: buffer
 * @deathnote: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *jojo, char *dssjjjlghhj, size_t *deathnote)
{
	ssize_t r = 0;

	if (*deathnote)
		return (0);
	r = read(jojo->readfd, dssjjjlghhj, READ_BUF_SIZE);
	if (r >= 0)
		*deathnote = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @jojo: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *jojo, char **ptr, size_t *length)
{
	static char dssjjjlghhj[READ_BUF_SIZE];
	static size_t deathnote, llelleelel;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (deathnote == llelleelel)
		deathnote = llelleelel = 0;

	r = read_buf(jojo, dssjjjlghhj, &llelleelel);
	if (r == -1 || (r == 0 && llelleelel == 0))
		return (-1);

	c = _strchr(dssjjjlghhj + deathnote, '\n');
	k = c ? 1 + (unsigned int)(c - dssjjjlghhj) : llelleelel;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, dssjjjlghhj + deathnote, k - deathnote);
	else
		_strncpy(new_p, dssjjjlghhj + deathnote, k - deathnote + 1);

	s += k - deathnote;
	deathnote = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @johnwick: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int johnwick)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
