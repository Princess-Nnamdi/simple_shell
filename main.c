#include "main.h"
/**
 * main- Entry point
 * @ac: the number of arguements passed
 * @argv: vector of arguements
 * Return: 0 on success
 **/
int main(int ac __attribute__((unused)), char **argv)
{
	char *shell_prompt = "MPshell@@ ", *ptr, *dup = NULL, *sep = " \n", *parse;
	size_t n = 0;
	ssize_t strd;
	int n_parse = 0, i;

	while (1)
	{
		printf("%s", shell_prompt);
		strd = getline(&ptr, &n, stdin);
		if (strd == -1)
		{
			printf("Disconnected...\n");
			return (-1);
		}
		dup = malloc(sizeof(char) * strd);
		if (dup == NULL)
		{
			perror("Malloc Error");
			return (-1);
		}
		strcpy(dup, ptr);
		parse = strtok(ptr, sep);
		for (; parse != NULL; n_parse++)
			parse = strtok(NULL, sep);
		n_parse++;
		argv = malloc(sizeof(char *) * strd);
		parse = strtok(dup, sep);
		for (i = 0; parse != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(parse));
			strcpy(argv[i], parse);
			parse = strtok(NULL, sep);
		}
		argv[i] = NULL;
		chill();
		executes_command(argv);
		free(dup), free(ptr);
	}
	return (0);
}
