#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>

/**
 * struct builtins - structure for printing various types
 * @builtin: type to print
 * @function: function to print
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(char **list_tokens);
} builtins;


char *read_user_input(void);
char **parse_user_input(char *_input);
void inf_loop(char **envp);
char *commandPath(char *command);
int execute(char **list_tokens, char **LT, char **en);
int builtins_list(char **list_tokens, char **envp);
int builtin_env(char **envp);
int builtin_exit(char **list_tokens);
int _atoi(char *s);
int _strcmp(char *string1, char *string2, int number);
int _strlen(const char *string);
int getStringListLength(char** stringList);
void copyStringList(char** dest, char** src, int size);
char* _strcpy(char* destination, const char* source);
char* _getenv(const char* name);
int _strncmp(const char* str1, const char* str2, size_t num);
char *_strdup(const char *str);
char* _strcat(char* destination, const char* source);


#endif
