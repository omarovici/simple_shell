#include "shell.h"

/**
 * hsh - main shell loop
 * @inffppppp: the parameter & return inffppppp struct
 * @messssi: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *inffppppp, char **messssi)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(inffppppp);
		if (interactive(inffppppp))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(inffppppp);
		if (r != -1)
		{
			set_info(inffppppp, messssi);
			builtin_ret = find_builtin(inffppppp);
			if (builtin_ret == -1)
				find_cmd(inffppppp);
		}
		else if (interactive(inffppppp))
			_putchar('\n');
		free_info(inffppppp, 0);
	}
	write_history(inffppppp);
	free_info(inffppppp, 1);
	if (!interactive(inffppppp) && inffppppp->status)
		exit(inffppppp->status);
	if (builtin_ret == -2)
	{
		if (inffppppp->err_num == -1)
			exit(inffppppp->status);
		exit(inffppppp->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - finds a builtin command
 * @inffppppp: the parameter & return inffppppp struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *inffppppp)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(inffppppp->argv[0], builtintbl[i].type) == 0)
		{
			inffppppp->line_count++;
			built_in_ret = builtintbl[i].func(inffppppp);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @inffppppp: the parameter & return inffppppp struct
 *
 * Return: void
 */
void find_cmd(info_t *inffppppp)
{
	char *path = NULL;
	int i, k;

	inffppppp->path = inffppppp->argv[0];
	if (inffppppp->linecount_flag == 1)
	{
		inffppppp->line_count++;
		inffppppp->linecount_flag = 0;
	}
	for (i = 0, k = 0; inffppppp->arg[i]; i++)
		if (!is_delim(inffppppp->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(inffppppp, _getenv(inffppppp, "PATH="), inffppppp->argv[0]);
	if (path)
	{
		inffppppp->path = path;
		fork_cmd(inffppppp);
	}
	else
	{
		if ((interactive(inffppppp) || _getenv(inffppppp, "PATH=")
			|| inffppppp->argv[0][0] == '/') && is_cmd(inffppppp, inffppppp->argv[0]))
			fork_cmd(inffppppp);
		else if (*(inffppppp->arg) != '\n')
		{
			inffppppp->status = 127;
			print_error(inffppppp, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an exec thread to run cmd
 * @inffppppp: the parameter & return inffppppp struct
 *
 * Return: void
 */
void fork_cmd(info_t *inffppppp)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(inffppppp->path, inffppppp->argv, get_environ(inffppppp)) == -1)
		{
			free_info(inffppppp, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(inffppppp->status));
		if (WIFEXITED(inffppppp->status))
		{
			inffppppp->status = WEXITSTATUS(inffppppp->status);
			if (inffppppp->status == 126)
				print_error(inffppppp, "Permission denied\n");
		}
	}
}
