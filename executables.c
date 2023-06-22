#include "main.h"

/**
 * executes_command - allows unix commands work in shell
 * @argv: array of arguements
 */
void executes_command(char **argv)
{
	char *cmd = NULL;

	if (argv != NULL)
		cmd = argv[0];
	get_path(cmd);

	if (execve(cmd, argv, NULL) == -1)
	{
		perror("Execve Error");
	}
}
