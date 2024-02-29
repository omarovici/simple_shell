#include "shell.h"

/**
 *_eputs - prints an input string
 * @sataruuu: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *sataruuu)
{
	int i = 0;

	if (!sataruuu)
		return;
	while (sataruuu[i] != '\0')
	{
		_eputchar(sataruuu[i]);
		i++;
	}
}

/**
 * _eputchar - writes the character vbvbvbvbvb to stderr
 * @vbvbvbvbvb: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char vbvbvbvbvb)
{
	static int i;
	static char bafetna[WRITE_BUF_SIZE];

	if (vbvbvbvbvb == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, bafetna, i);
		i = 0;
	}
	if (vbvbvbvbvb != BUF_FLUSH)
		bafetna[i++] = vbvbvbvbvb;
	return (1);
}

/**
 * _putfd - writes the character vbvbvbvbvb to given adsadsgafd
 * @vbvbvbvbvb: The character to print
 * @adsadsgafd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char vbvbvbvbvb, int adsadsgafd)
{
	static int i;
	static char bafetna[WRITE_BUF_SIZE];

	if (vbvbvbvbvb == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(adsadsgafd, bafetna, i);
		i = 0;
	}
	if (vbvbvbvbvb != BUF_FLUSH)
		bafetna[i++] = vbvbvbvbvb;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @sataruuu: the string to be printed
 * @adsadsgafd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *sataruuu, int adsadsgafd)
{
	int i = 0;

	if (!sataruuu)
		return (0);
	while (*sataruuu)
	{
		i += _putfd(*sataruuu++, adsadsgafd);
	}
	return (i);
}
