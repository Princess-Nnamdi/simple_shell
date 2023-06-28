#include "main.h"

/**
 * _setenv - sets a new or modify an existing variable
 * @var: variable to be set
 * @val: value of the set variable
 * Return: 0 on success or -1 on failure
 */

int _setenv(char *var, char *val)
{
	if (getenv(var) != NULL)
	{
		if (setenv(var, val, 1) == -1)
		{
			perror("setenv Error");
			return (-1);
		}
	}
	else
	{
		if (setenv(var, val, 1) == -1)
		{
			perror("setenv Error");
			return (-1);
		}
	}
	return (0);
}
/**
 * _unsetenv - unsets a new variable or modify an existing one
 * @var: variable to be set
 * Return: 0 on success or -1 on failure
 */
int _unsetenv(char *var)
{
	if (getenv(var) != NULL)
	{
		if (unsetenv(var) == -1)
		{
			perror("unsetenv Error");
			return (-1);
		}
	}
	else
	{
		write(STDERR_FILENO, "unsetenv error: unfound variable\n", 35);
		return (-1);
	}
	return (0);
}
/**
 * executes_command - allows unix commands work in shell
 * @argv: array of arguements
 * Return: 0
 */
int executes_command(char **argv)
{
	pid_t kid;
	char *cmd = NULL, *cmds = NULL, *home = NULL, *oldpwd = NULL;
	char *envp[] = {(char *) "PATH=/bin", 0};
	int final, exit_status = 0;

	if (strcmp(argv[0], "cd") == 0)
	{
		if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
		{
			home = getenv("HOME");
			if (home == NULL)
			{
				perror("getenv error");
				return (-1);
			}
			return (_chdir(home));
		}
		else if (strcmp(argv[1], "-") == 0)
		{
			oldpwd = getenv("OLDPWD");
			if (oldpwd == NULL)
			{
				perror("getenv error");
				return (-1);
			}
			return (_chdir(oldpwd));
		}
		else
			return (_chdir(argv[1]));
	}
	else if (strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] == NULL || argv[2] == NULL)
		{
			write(STDERR_FILENO, "setenv error: invalid argument\n", 32);
			return (-1);
		}
		final = (_setenv(argv[1], argv[2]));
		if (final == 0)
			return (final);
	}
	else if (strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] == NULL)
		{
			write(STDERR_FILENO, "unsetenv error: invalid argument\n", 33);
			return (-1);
		}
		return (_unsetenv(argv[1]));
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1] != NULL)
			exit_status = atoi(argv[1]);
		exit(exit_status);
	}
	kid = fork();
	if (kid == -1)
		return (-1);
	if (kid == 0)
	{
		if (argv != NULL)
			cmd = argv[0];
		cmds = get_path(cmd);
		if (execve(cmds, argv, envp) == -1)
		{
			perror("Execve Error");
		}
	}
	else
		wait(NULL);
	return (0);
}
