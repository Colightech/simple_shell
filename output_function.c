#include "shell.h"
/**
 *  _prerror - Print Custome Error
 * @argv:Program Name
 * @b: Error Count
 * @str:Command
 * Return: Void
 */
void _prerror(char **argv, int b, char **str)
{
	char *err = _itoa(b);

	PRINT_OUT(argv[0]);
	PRINT_OUT(": ");
	PRINT_OUT(err);
	PRINT_OUT(": ");
	PRINT_OUT(str[0]);
	PRINT_OUT(": invalid entery: ");
	PRINT_OUT(str[1]);
	PRINT_OUT("\n");
	free(err);
}
