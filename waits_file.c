#include "main.h"

/**
 * chill- implements the wait function
 * Return: 0 on success
 **/

int chill(void)
{
	pid_t kid, middle_kid;
	int status;
	
	kid = fork();
	if (kid == -1)
	{
		perror("Fork Failed...\n");
		return (1);
	}
	if (kid == 0)
	{
		printf("Kid process");
		exit(0);
	}
	else
	{
		middle_kid = waitpid(kid, &status, 0);
		if (middle_kid == -1)
		{
			perror("Wait failed");
			return (1);
		}
		if (WIFEXITED(status))
			printf("Child process %d exited with status %d\n", middle_kid, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("Child process %d terminated by signal %d\n", middle_kid, WTERMSIG(status));
		else
			printf("Child process %d terminated\n", middle_kid);

	}
	return (0);
}
