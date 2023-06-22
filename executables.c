#include "main.h"

/**
 * executes_command - allows unix commands work in shell
 * @argv: array of arguements
 */
void executes_command(char **argv)
{
	char *cmd = NULL, *cmds = NULL;

	if (argv != NULL)
		cmd = argv[0];
	cmds = get_path(cmd);

	if (execve(cmds, argv, NULL) == -1)
	{
		perror("Execve Error");
	}
}
