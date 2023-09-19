#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *insert, **str;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		accept_file(argv[1], argv);
	signal(SIGINT, handle_gesture);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompt();
		insert = _getline();
		if (insert[0] == '\0')
		{
			continue;
		}
		history(insert);
		str = parse_cmd(insert);
		if (_strcmp(str[0], "exit") == 0)
		{
			exit_bul(str, insert, argv, counter);
		}
		else if (check_builtin(str) == 0)
		{
			st = handling_builtin(str, st);
			free_all(str, insert);
			continue;
		}
		else
		{
			st = check_str(str, insert, counter, argv);

		}
		free_all(str, insert);
	}
	return (statue);
}
/**
 * check_builtin - check builtin
 *
 * @str: command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **str)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int x = 0;
		if (*str == NULL)
	{
		return (-1);
	}

	while ((fun + x)->command)
	{
		if (_strcmp(str[0], (fun + x)->command) == 0)
			return (0);
		x++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int x;

	for (x = 0; environ[x]; x++)
		envi[x] = _strdup(environ[x]);
	envi[x] = NULL;
}
