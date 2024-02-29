#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @qsqwyerh: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(info_t *qsqwyerh)
{
	if (!qsqwyerh->environ || qsqwyerh->env_changed)
	{
		qsqwyerh->environ = list_to_strings(qsqwyerh->env);
		qsqwyerh->env_changed = 0;
	}

	return (qsqwyerh->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @qsqwyerh: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @ffffffsdgagsdjfdfkgf: the string env ffffffsdgagsdjfdfkgf property
 */
int _unsetenv(info_t *qsqwyerh, char *ffffffsdgagsdjfdfkgf)
{
	list_t *node = qsqwyerh->env;
	size_t i = 0;
	char *p;

	if (!node || !ffffffsdgagsdjfdfkgf)
		return (0);

	while (node)
	{
		p = starts_with(node->str, ffffffsdgagsdjfdfkgf);
		if (p && *p == '=')
		{
			qsqwyerh->env_changed = delete_node_at_index(&(qsqwyerh->env), i);
			i = 0;
			node = qsqwyerh->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (qsqwyerh->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @qsqwyerh: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @ffffffsdgagsdjfdfkgf: the string env ffffffsdgagsdjfdfkgf property
 * @value: the string env ffffffsdgagsdjfdfkgf value
 *  Return: Always 0
 */
int _setenv(info_t *qsqwyerh, char *ffffffsdgagsdjfdfkgf, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!ffffffsdgagsdjfdfkgf || !value)
		return (0);

	buf = malloc(_strlen(ffffffsdgagsdjfdfkgf) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, ffffffsdgagsdjfdfkgf);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = qsqwyerh->env;
	while (node)
	{
		p = starts_with(node->str, ffffffsdgagsdjfdfkgf);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			qsqwyerh->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(qsqwyerh->env), buf, 0);
	free(buf);
	qsqwyerh->env_changed = 1;
	return (0);
}
