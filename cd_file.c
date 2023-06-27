#include "main.h"

/**
 * _chdir- changes present working directory
 * @dir: directory to be changed to
 * Return: 0 on success or -1
 **/

int _chdir(char *dir)
{
	char *last_dir = NULL, *curr_dir = NULL;

	last_dir = getcwd(NULL, 0);
	if (last_dir == NULL)
	{
		perror("getcwd error");
		return (-1);
	}
	if (chdir(dir) == -1)
	{
		perror("chdir error");
		free(last_dir);
		return (-1);
	}
	curr_dir = getcwd(NULL, 0);
	if (curr_dir == NULL)
	{
		perror("getcwd error");
		free(last_dir);
		return (-1);
	}
	if (setenv("PWD", curr_dir, 1) == -1)
	{
		perror("setenv error");
		free(last_dir);
		free(curr_dir);
		return (-1);
	}
	free(last_dir);
	free(curr_dir);
	return (0);
}
