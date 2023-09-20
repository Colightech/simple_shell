#include "shell.h"

/**
 * handling_builtin - Handle Builtin Command
 * @str: Parsed Command
 * @err: statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handling_builtin(char **str, int err)
{
	 bul_t billed[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"help", display_help},
		{"echo", echo_bul},
		{"history", history_dis},
		{NULL, NULL}
	};
	int x = 0;

	while ((billed + x)->command)
	{
		if (_strcmp(str[0], (billed + x)->command) == 0)
		{
			return ((billed + x)->fun(str, err));
		}
		x++;
	}
	return (-1);
}
/**
 * check_str - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @str: Parsed Command
 * @insert: User Input
 * @b: Shell Excution Time Case of Command Not Found
 * @argv: Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_str(char **str, char *insert, int b, char **argv)
{
	int status;
	pid_t child_process;

	if (*str == NULL)
	{
		return (-1);
	}

	child_process = fork();
	if (child_process == -1)
	{
		perror("Error");
		return (-1);
	}

	if (child_process == 0)
	{
		if (_strncmp(*str, "./", 2) != 0 && _strncmp(*str, "/", 1) != 0)
		{
			path_cmd(str);
		}

		if (execve(*str, str, environ) == -1)
		{
			print_error(str[0], b, argv);
			free(insert);
			free(str);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * handle_gesture - Handle ^C
 * @signal: Captured Signal
 * Return: Void
 */
void handle_gesture(int signal)
{
	if (signal == SIGINT)
	{
		PRINT_OUT("\n$ ");
	}
}
