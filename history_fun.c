#include "shell.h"
/**
 * history - Get updated By User Input
 * @insert: User Input
 * Return: -1 Fail 0 Succes
 */
int history(char *insert)
{
	char *filename = ".chris_favour_simple_shell_history";
	ssize_t fd, w;
	int lent = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (insert)
	{
		while (insert[lent])
			lent++;
		w = write(fd, insert, lent);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */
void free_env(char **env)
{
	int x;

	for (x = 0; env[x]; x++)
	{
		free(env[x]);
	}
}
