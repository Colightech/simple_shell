#include "shell.h"
/**
 * accept_file - Read Command From File
 * @filename:Filename
 * @argv:Program Name
 * Return: -1 or  0
 */

void accept_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t lent = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &lent, fp)) != -1)
	{
		counter++;
		treat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **str;
	int st = 0;

	str = parse_cmd(line);

		if (_strncmp(str[0], "exit", 4) == 0)
		{
			exit_bul_for_file(str, line, fp);
		}
		else if (check_builtin(str) == 0)
		{
			st = handling_builtin(str, st);
			free(str);
		}
		else
		{
			st = check_str(str, line, counter, argv);
			free(str);
		}
}
/**
 * exit_bul_for_file - Exit Shell Case Of File
 * @line: Line From A File
 * @str: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_bul_for_file(char **str, char *line, FILE *fd)
{
	int statue, x = 0;

	if (str[1] == NULL)
	{
		free(line);
		free(str);
		fclose(fd);
		exit(errno);
	}
	while (str[1][x])
	{
		if (_isalpha(str[1][x++]) < 0)
		{
			perror("invalid entery");
		}
	}
	statue = _atoi(str[1]);
	free(line);
	free(str);
	fclose(fd);
	exit(statue);



}
