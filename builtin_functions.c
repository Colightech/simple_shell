#include "shell.h"
/**
 * exit_bul - Exit Statue Shell
 * @str: Parsed Command
 * @insert: User Input
 * @argv: Program Name
 * @b: Excute Count
 * Return: Void (Exit Statue)
 */
void  exit_bul(char **str, char *insert, char **argv, int b)
{
	int statue, x = 0;

	if (str[1] == NULL)
	{
		free(insert);
		free(str);
		exit(EXIT_SUCCESS);
	}
	while (str[1][x])
	{
		if (_isalpha(str[1][x++]) != 0)
		{
			_prerror(argv, b, str);
			break;
		}
		else
		{
			statue = _atoi(str[1]);
			free(insert);
			free(str);
			exit(statue);
		}
	}
}


/**
 * change_dir - Change Dirctorie from one to another
 * @str: Parsed Command
 * @err: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */
int change_dir(char **str, __attribute__((unused))int err)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (str[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(str[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(str[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
/**
 * dis_env - Display Enviroment Variable
 * @str: Parsed Command
 * @err: Statue of Last command Excuted
 * Return:Always 0
 */
int dis_env(__attribute__((unused)) char **str,
		__attribute__((unused)) int err)
{
	size_t x;
	int lent;

	for (x = 0; environ[x] != NULL; x++)
	{
		lent = _strlen(environ[x]);
		write(1, environ[x], lent);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
 * display_help - Displaying Help For Builtin
 * @str: Parsed input string
 * @err: Statue Of Last Command Excuted
 * Return: 0 Succes -1 Fail
 */
int display_help(char **str, __attribute__((unused))int err)
{
	int fd, fw, rd = 1;
	char b;

	fd = open(str[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		return (0);
	}
	while (rd > 0)
	{
		rd = read(fd, &b, 1);
		fw = write(STDOUT_FILENO, &b, rd);
		if (fw < 0)
		{
			return (-1);
		}
	}
	_putchar('\n');
	return (0);
}
/**
 * echo_bul - Excute Echo Cases
 * @st: Status Of Last Command implemented
 * @str: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_bul(char **str, int st)
{
	char *path;
	unsigned int  child_pid = getppid();

	if (_strncmp(str[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINT_OUT("\n");
	}
	else if (_strncmp(str[1], "$$", 2) == 0)
	{
		print_number(child_pid);
		PRINT_OUT("\n");

	}
	else if (_strncmp(str[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINT_OUT(path);
		PRINT_OUT("\n");
		free(path);

	}
	else
		return (print_echo(str));

	return (1);
}
