iii#include "main.h"

/**
 * main- Entry point
 * @ac: the number of arguements passed
 * @argv: vector of arguements
 * Return: 0 on success
 **/

int main(int ac, char **argv)
{
	char *shell_prompt = "MPshell@@ ";
	char *lineptr, *lineptr_dup = NULL, *sep = " \n";
	size_t n = 0;
	(void)ac; (void)argv;
	ssize_t string;
	char *parse;
	int n_parse = 0, i;
	
	while (1)
	{
		printf("%s", shell_prompt);
		string = getline(&lineptr, &n, stdin);
		if (string == -1)
		{
			printf("Disconnected...\n");
			return (-1);
		}
		lineptr_dup = malloc(sizeof(char) * string);
		if (lineptr_dup == NULL)
		{
			perror("Malloc Error");
			return (-1);
		}
		strcpy(lineptr_dup, lineptr);
		parse = strtok(lineptr, sep);
		while (parse != NULL);
		{
			n_parse++;
			parse = strtok(NULL, sep);
		}
		n_parse++;
		argv = malloc(sizeof(char *) * string);
		parse = strtok(lineptr_dup, sep);
		printf("%s", lineptr);
		free(lineptr);
	}
	return (0);
}
