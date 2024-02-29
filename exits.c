#include "shell.h"

/**
 **_strncpy - copies a string
 *@ddedededededede: the destination string to be copied to
 *@sadfghjhgfd: the source string
 *@numnumiii: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *ddedededededede, char *sadfghjhgfd, int numnumiii)
{
	int i, j;
	char *s = ddedededededede;

	i = 0;
	while (sadfghjhgfd[i] != '\0' && i < numnumiii - 1)
	{
		ddedededededede[i] = sadfghjhgfd[i];
		i++;
	}
	if (i < numnumiii)
	{
		j = i;
		while (j < numnumiii)
		{
			ddedededededede[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@ddedededededede: the first string
 *@sadfghjhgfd: the second string
 *@numnumiii: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *ddedededededede, char *sadfghjhgfd, int numnumiii)
{
	int i, j;
	char *s = ddedededededede;

	i = 0;
	j = 0;
	while (ddedededededede[i] != '\0')
		i++;
	while (sadfghjhgfd[j] != '\0' && j < numnumiii)
	{
		ddedededededede[i] = sadfghjhgfd[j];
		i++;
		j++;
	}
	if (j < numnumiii)
		ddedededededede[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
