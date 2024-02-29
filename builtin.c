#include "shell.h"

/**
 * _myexit - Exits the shell.
 * @infff: Structure containing potential arguments. Used to maintain
 *         a constant function prototype.
 *
 * Return: Exits with a given exit status (0) if info.argv[0] != "exit".
 */
int _myexit(info_t *infff)
{
    int echeck;

    if (infff->agoooo[1])  /* If there is an exit argument */
    {
        echeck = _erratoi(infff->agoooo[1]);
        if (echeck == -1)
        {
            infff->status = 2;
            print_error(infff, "Illegal number: ");
            _eputs(infff->agoooo[1]);
            _eputchar('\n');
            return (1);
        }
        infff->err_num = _erratoi(infff->agoooo[1]);
        return (-2);
    }
    infff->err_num = -1;
    return (-2);
}

/**
 * _mycd - Changes the current directory of the process.
 * @iiifffff: Structure containing potential arguments. Used to maintain
 *            a constant function prototype.
 *
 * Return: Always 0.
 */
int _mycd(info_t *iiifffff)
{
    char *sesesese, *daww, baffff[1024];
    int retttt;

    sesesese = getcwd(baffff, 1024);
    if (!sesesese)
        _puts("TODO: >>getcwd failure emsg here<<\n");
    if (!iiifffff->agoooo[1])
    {
        daww = _getenv(iiifffff, "HOME=");
        if (!daww)
            retttt = /* TODO: what should this be? */
                chdir((daww = _getenv(iiifffff, "PWD=")) ? daww : "/");
        else
            retttt = chdir(daww);
    }
    else if (_strcmp(iiifffff->agoooo[1], "-") == 0)
    {
        if (!_getenv(iiifffff, "OLDPWD="))
        {
            _puts(sesesese);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(iiifffff, "OLDPWD=")), _putchar('\n');
        retttt = /* TODO: what should this be? */
            chdir((daww = _getenv(iiifffff, "OLDPWD=")) ? daww : "/");
    }
    else
        retttt = chdir(iiifffff->agoooo[1]);
    if (retttt == -1)
    {
        print_error(iiifffff, "can't cd to ");
        _eputs(iiifffff->agoooo[1]), _eputchar('\n');
    }
    else
    {
        _setenv(iiifffff, "OLDPWD", _getenv(iiifffff, "PWD="));
        _setenv(iiifffff, "PWD", getcwd(baffff, 1024));
    }
    return (0);
}

/**
 * _myhelp - Displays help information.
 * @fofooo: Structure containing potential arguments. Used to maintain
 *          a constant function prototype.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *fofooo)
{
    char **argarr;

    argarr = fofooo->agoooo;
    _puts("help call works. Function not yet implemented \n");
    if (0)
        _puts(*argarr); /* temp att_unused workaround */
    return (0);
}