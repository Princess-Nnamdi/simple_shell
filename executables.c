#include "main.h"

/**
 * executes_command - allows unix commands work in shell
 * @argv: array of arguements
 * Return: 0
 */
int executes_command(char **argv)
{
	pid_t kid;

	char *cmd = NULL, *cmds = NULL;
	char *envp[] = {(char *) "PATH=/bin", 0};

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
