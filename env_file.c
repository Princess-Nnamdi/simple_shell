#include "main.h"

/**
 * environment- Implement the env built-in,
 * that prints the current environment
 **/

void environment(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
