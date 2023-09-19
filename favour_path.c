#include "shell.h"

/**
 * path_cmd -  Search  $PATH For Excutable
 * @str: Input string
 * Return: 1  Failure  0  Success.
 */
int path_cmd(char **str)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*str, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*str = _strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * build - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *build(char *token, char *value)
{
	char *str;
	size_t lent;

	lent = _strlen(value) + _strlen(token) + 2;
	str = malloc(sizeof(char) * lent);
	if (str == NULL)
	{
		return (NULL);
	}

	memset(str, 0, lent);

	str = _strcat(str, value);
	str = _strcat(str, "/");
	str = _strcat(str, token);

	return (str);
}
/**
 * _getenv - Gets Enviroment Variable By Name
 * @name: Env Variable Name
 * Return: The Value of the Environment Variable or NULL.
 */
char *_getenv(char *name)
{
	size_t nl, vl;
	char *value;
	int a, x, j;

	nl = _strlen(name);
	for (a = 0 ; environ[a]; a++)
	{
		if (_strncmp(name, environ[a], nl) == 0)
		{
			vl = _strlen(environ[a]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("memory allocatio fail");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[a][x]; x++, j++)
			{
				value[j] = environ[a][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
