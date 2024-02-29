#include "shell.h"

/**
 * _myexit - exits the shell
 * @infffff: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if infffff.argv[0] != "exit"
 */
int _myexit(info_t *infffff)
{
	int echiikkk;

	if (infffff->argv[1])  /* If there is an exit arguement */
	{
		echiikkk = _erratoi(infffff->argv[1]);
		if (echiikkk == -1)
		{
			infffff->status = 2;
			print_error(infffff, "Illegal number: ");
			_eputs(infffff->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infffff->err_num = _erratoi(infffff->argv[1]);
		return (-2);
	}
	infffff->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @infffff: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *infffff)
{
	char *swswsw, *dddooo, bffff[1024];
	int ret;

	swswsw = getcwd(bffff, 1024);
	if (!swswsw)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!infffff->argv[1])
	{
		dddooo = _getenv(infffff, "HOME=");
		if (!dddooo)
			ret = /* TODO: what should this be? */
				chdir((dddooo = _getenv(infffff, "PWD=")) ? dddooo : "/");
		else
			ret = chdir(dddooo);
	}
	else if (_strcmp(infffff->argv[1], "-") == 0)
	{
		if (!_getenv(infffff, "OLDPWD="))
		{
			_puts(swswsw);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(infffff, "OLDPWD=")), _putchar('\n');
		ret = /* TODO: what should this be? */
			chdir((dddooo = _getenv(infffff, "OLDPWD=")) ? dddooo : "/");
	}
	else
		ret = chdir(infffff->argv[1]);
	if (ret == -1)
	{
		print_error(infffff, "can't cd to ");
		_eputs(infffff->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(infffff, "OLDPWD", _getenv(infffff, "PWD="));
		_setenv(infffff, "PWD", getcwd(bffff, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @infffff: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *infffff)
{
	char **arguuuu;

	arguuuu = infffff->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arguuuu); /* temp att_unused workaround */
	return (0);
}
