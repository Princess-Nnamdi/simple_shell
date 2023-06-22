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
	char *lineptr, *lineptr_dup = NULL, *sep = " \n", *parse;
	size_t n = 0;
	ssize_t strd;
	int n_parse = 0, i;
	(void)ac;

	while (1)
	{
		printf("%s", shell_prompt);
		strd = getline(&lineptr, &n, stdin);
		if (strd == -1)
		{
			printf("Disconnected...\n");
			return (-1);
		}
		lineptr_dup = malloc(sizeof(char) * strd);
		if (lineptr_dup == NULL)
		{
			perror("Malloc Error");
			return (-1);
		}
		strcpy(lineptr_dup, lineptr);
		parse = strtok(lineptr, sep);
		while (parse != NULL)
		{
			n_parse++;
			parse = strtok(NULL, sep);
		}
		n_parse++;
		argv = malloc(sizeof(char *) * strd);
		parse = strtok(lineptr_dup, sep);
		for (i = 0; parse != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(parse));
			strcpy(argv[i], parse);
			parse = strtok(NULL, sep);
		}
		argv[i] = NULL;
		executes_command(argv);
		free(lineptr_dup), free(lineptr);
	}
	return (0);
}
