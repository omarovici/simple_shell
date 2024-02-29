#include "shell.h"

/**
 * _myenv - prints the current environment
 * @iiiiiiiuuuuu: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *iiiiiiiuuuuu)
{
	print_list_str(iiiiiiiuuuuu->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @iiiiiiiuuuuu: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *iiiiiiiuuuuu, const char *name)
{
	list_t *neeeddd = iiiiiiiuuuuu->env;
	char *p;

	while (neeeddd)
	{
		p = starts_with(neeeddd->str, name);
		if (p && *p)
			return (p);
		neeeddd = neeeddd->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @iiiiiiiuuuuu: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *iiiiiiiuuuuu)
{
	if (iiiiiiiuuuuu->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(iiiiiiiuuuuu, iiiiiiiuuuuu->argv[1], iiiiiiiuuuuu->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @iiiiiiiuuuuu: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *iiiiiiiuuuuu)
{
	int i;

	if (iiiiiiiuuuuu->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= iiiiiiiuuuuu->argc; i++)
		_unsetenv(iiiiiiiuuuuu, iiiiiiiuuuuu->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @iiiiiiiuuuuu: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *iiiiiiiuuuuu)
{
	list_t *neeeddd = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&neeeddd, environ[i], 0);
	iiiiiiiuuuuu->env = neeeddd;
	return (0);
}
