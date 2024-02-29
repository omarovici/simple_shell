#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @unfffffff: the unfffffff struct
 * @bot: bot to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *unfffffff, char *bot)
{
	struct stat st;

	(void)unfffffff;
	if (!bot || stat(bot, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @unfffffff: the unfffffff struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full bot of cmd if found or NULL
 */
char *find_path(info_t *unfffffff, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *bot;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(unfffffff, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			bot = dup_chars(pathstr, curr_pos, i);
			if (!*bot)
				_strcat(bot, cmd);
			else
			{
				_strcat(bot, "/");
				_strcat(bot, cmd);
			}
			if (is_cmd(unfffffff, bot))
				return (bot);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
