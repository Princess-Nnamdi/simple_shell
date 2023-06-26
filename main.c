#include "main.h"
/**
 * main- Entry point
 * @ac: the number of arguements passed
 * @argv: vector of arguements
 * @env: prints the environment
 * Return: 0 on success
 **/
int main(int ac __attribute__((unused)), char **argv, char **env)
{
	char *shell_prompt = "MPshell@@ ", *ptr, *dup = NULL, *sep = " \n", *parse;
	size_t n = 0;
	ssize_t strd;
	int n_parse = 0, i, j = 0;
	
	while (1)
	{
		printf("%s", shell_prompt);
		strd = getline(&ptr, &n, stdin);
		if ((strd == -1) || strcmp(ptr, "exit\n") == 0)
		{
			printf("Disconnected...\n");
			exit(0);
		}
		dup = malloc(sizeof(char) * (strd + 1));
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
		argv = malloc(sizeof(char *) * (n_parse + 1));
		parse = strtok(dup, sep);
		for (i = 0; parse != NULL; i++)
		{
			argv[i] = strdup(parse);
			parse = strtok(NULL, sep);
		}
		argv[i] = NULL;
		if (strcmp(argv[0], "env") == 0)
		{
		for (; env[j] != NULL; j++)
                printf("%s\n", env[j]);
		}
		else
		executes_command(argv);
		free(dup), free(argv), free(ptr);
	}
	return (0);
}
