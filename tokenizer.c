#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @storshka: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *storshka, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (storshka == NULL || storshka[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; storshka[i] != '\0'; i++)
		if (!is_delim(storshka[i], d) && (is_delim(storshka[i + 1], d) || !storshka[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(storshka[i], d))
			i++;
		k = 0;
		while (!is_delim(storshka[i + k], d) && storshka[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = storshka[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @storshka: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *storshka, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (storshka == NULL || storshka[0] == 0)
		return (NULL);
	for (i = 0; storshka[i] != '\0'; i++)
		if ((storshka[i] != d && storshka[i + 1] == d) ||
		    (storshka[i] != d && !storshka[i + 1]) || storshka[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (storshka[i] == d && storshka[i] != d)
			i++;
		k = 0;
		while (storshka[i + k] != d && storshka[i + k] && storshka[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = storshka[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
