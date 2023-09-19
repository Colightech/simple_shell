#ifndef _SHELL_H_
#define _SHELL_H_

/******* environ var *******/

extern char **environ;

/******* MACROS *******/

#define BUFFER_SIZE 1024
#define DELIMI " \t\r\n\a"
#define PRINT_OUT(c) (write(STDOUT_FILENO, c, _strlen(c)))

/******* LIBRARIES *******/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>





/******* STRING FUNCTION *******/

char *_strtok(char *str, const char *tok);
unsigned int check_delim(char b, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int b);
void array_rev(char *arr, int len);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char b);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/******* MEMORIE  MANGMENT *******/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/******* INPUT Function *******/

void prompt(void);
void handle_gesture(int signal);
char *_getline(void);

/******* Command parser and extractor *******/

int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *str);
int handling_builtin(char **str, int err);
void accept_file(char *filename, char **argv);
char *build(char *token, char *value);
int check_builtin(char **str);
void creat_envi(char **envi);
int check_str(char **tokens, char *line, int count, char **argv);
void treat_file(char *line, int counter, FILE *fd, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);

/******* BUILTIN FUNC *******/

void hashtag_handle(char *buff);
int history(char *insert);
int history_dis(char **cmd, int er);
int dis_env(char **str, int err);
int change_dir(char **str, int err);
int display_help(char **str, int err);
int echo_bul(char **str, int er);
void  exit_bul(char **str, char *insert, char **argv, int b);
int print_echo(char **str);

/******* error handle and Printer *******/
void print_number(unsigned int m);
void print_number_in(int m);
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int b, char **str);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
