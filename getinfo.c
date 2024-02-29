#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @ssdskfgfkhkhfg: struct address
 */
void clear_info(info_t *ssdskfgfkhkhfg)
{
	ssdskfgfkhkhfg->arg = NULL;
	ssdskfgfkhkhfg->argv = NULL;
	ssdskfgfkhkhfg->path = NULL;
	ssdskfgfkhkhfg->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @ssdskfgfkhkhfg: struct address
 * @av: argument vector
 */
void set_info(info_t *ssdskfgfkhkhfg, char **av)
{
	int i = 0;

	ssdskfgfkhkhfg->fname = av[0];
	if (ssdskfgfkhkhfg->arg)
	{
		ssdskfgfkhkhfg->argv = strtow(ssdskfgfkhkhfg->arg, " \t");
		if (!ssdskfgfkhkhfg->argv)
		{

			ssdskfgfkhkhfg->argv = malloc(sizeof(char *) * 2);
			if (ssdskfgfkhkhfg->argv)
			{
				ssdskfgfkhkhfg->argv[0] = _strdup(ssdskfgfkhkhfg->arg);
				ssdskfgfkhkhfg->argv[1] = NULL;
			}
		}
		for (i = 0; ssdskfgfkhkhfg->argv && ssdskfgfkhkhfg->argv[i]; i++)
			;
		ssdskfgfkhkhfg->argc = i;

		replace_alias(ssdskfgfkhkhfg);
		replace_vars(ssdskfgfkhkhfg);
	}
}

/**
 * free_info - frees info_t struct fields
 * @ssdskfgfkhkhfg: struct address
 * @alldlslfdl: true if freeing alldlslfdl fields
 */
void free_info(info_t *ssdskfgfkhkhfg, int alldlslfdl)
{
	ffree(ssdskfgfkhkhfg->argv);
	ssdskfgfkhkhfg->argv = NULL;
	ssdskfgfkhkhfg->path = NULL;
	if (alldlslfdl)
	{
		if (!ssdskfgfkhkhfg->cmd_buf)
			free(ssdskfgfkhkhfg->arg);
		if (ssdskfgfkhkhfg->env)
			free_list(&(ssdskfgfkhkhfg->env));
		if (ssdskfgfkhkhfg->history)
			free_list(&(ssdskfgfkhkhfg->history));
		if (ssdskfgfkhkhfg->alias)
			free_list(&(ssdskfgfkhkhfg->alias));
		ffree(ssdskfgfkhkhfg->environ);
			ssdskfgfkhkhfg->environ = NULL;
		bfree((void **)ssdskfgfkhkhfg->cmd_buf);
		if (ssdskfgfkhkhfg->readfd > 2)
			close(ssdskfgfkhkhfg->readfd);
		_putchar(BUF_FLUSH);
	}
}
