#include "main.h"

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
