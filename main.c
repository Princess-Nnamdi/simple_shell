#include "main.h"

/**
 * main- Entry point
 * @ac: the number of arguements passed
 * @argv: vector of arguements
 * Return: 0 on success
 **/

int main(int ac, char **argv)
{
	char *shell_prompt = "MPshell@@ ";
	char *lineptr;
	size_t n = 0;
	(void)ac; (void)argv;

	printf("%s", shell_prompt);
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);
	free(lineptr);
	return (0);
}
