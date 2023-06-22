#include "main.h"

/**
 * get_path - provides the path of the commands
 * @cmd: commands to be used
 * Return: path
 */
char *get_path(char *cmd)
{
	char *path, *path_dup, *path_parse, *file_path;
	int cmd_len, dir_len;
	struct stat buff;

	path = getenv("PATH");
	if (path != NULL)
	{
		path_dup = strdup(path);
		cmd_len = strlen(cmd);
		path_parse = strtok(path_dup, ":");

		while (path_parse != NULL)
		{
			dir_len = strlen(path_parse);
			file_path = malloc(cmd_len + dir_len + 2);
			strcpy(file_path, path_parse);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buff) == 0)
			{
				free(path_dup);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_parse = strtok(NULL, ":");
			}
		}
		free(path_dup);
		if (stat(cmd, &buff) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}
