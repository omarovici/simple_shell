#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *inf)
{
    return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @clcl: the char to check
 * @del: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char clcl, char *del)
{
    while (*del)
        if (*del++ == clcl)
            return (1);
    return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if siiiii is alphabetic, 0 otherwise
 */

int _isalpha(int siiiii)
{
    if ((siiiii >= 'a' && siiiii <= 'z') || (siiiii >= 'A' && siiiii <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 *_atoi - converts a string to an integer
 *@ceeeeee: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *ceeeeee)
{
    int i, sig = 1, check = 0, out;
    unsigned int rere = 0;

    for (i = 0; ceeeeee[i] != '\0' && check != 2; i++)
    {
        if (ceeeeee[i] == '-')
            sig *= -1;

        if (ceeeeee[i] >= '0' && ceeeeee[i] <= '9')
        {
            check = 1;
            rere *= 10;
            rere += (ceeeeee[i] - '0');
        }
        else if (check == 1)
            check = 2;
    }

    if (sig == -1)
        out = -rere;
    else
        out = rere;

    return (out);
}