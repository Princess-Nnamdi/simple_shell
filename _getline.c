#include "main.h"

/**
 * _getline - gets characters from keyboard
 * Return: characters
 */

/**ssize_t _getline(char **ptr, size_t *n)
{
	ssize_t b_size;
	
	if (ptr == NULL || n == NULL)
		return (-1);
	*ptr = NULL;
	*n = 0;

	while (1)
	{
		if (index >= rem)
		{
			rem = read(STDIN_FILENO, buffer, READ_SIZE);
			index =  0;
			if (rem == 0)
			break;
			else if (rem == -1)
				return (-1);
		}
		if (str_read
	}
			
}**/
