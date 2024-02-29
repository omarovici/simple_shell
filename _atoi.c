#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @i: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(inf *i)
{
    return (isatty(STDIN_FILENO) && i->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @ce: the char to check
 * @de: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char ce, char *de)
{
    while (*de)
        if (*de++ == ce)
            return (1);
    return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@ci: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int ci)
{
    if ((ci >= 'a' && ci <= 'z') || (ci >= 'A' && ci <= 'Z'))
        return (1);
    else
        return (0);
}

/**
 *_atoi - converts a string to an integer
 *@se: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *se)
{
    int i, signee = 1, ffl = 0, out;
    unsigned int sum = 0;

    for (i = 0;  se[i] != '\0' && ffl != 2; i++)
    {
        if (se[i] == '-')
            signee *= -1;

        if (se[i] >= '0' && se[i] <= '9')
        {
            ffl = 1;
            sum *= 10;
            sum += (se[i] - '0');
        }
        else if (ffl == 1)
            ffl = 2;
    }

    if (signee == -1)
        out = -sum;
    else
        out = sum;

    return (out);
}
