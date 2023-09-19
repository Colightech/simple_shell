#include "shell.h"

/**
 * history_dis - Display History Of User Input
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int history_dis(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *filename = ".chris_favour_simple_shell_history";
	FILE *fp;
	char *line = NULL;
	size_t lent = 0;
	int counter = 0;
	char *err;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &lent, fp)) != -1)
	{
		counter++;
		err = _itoa(counter);
		PRINT_OUT(err);
		free(err);
		PRINT_OUT(" ");
		PRINT_OUT(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
/**
 * print_echo - Execute Echo
 * @str: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int print_echo(char **str)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
	if (execve("/bin/echo", str, environ) == -1)
	{
		return (-1);
	}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
