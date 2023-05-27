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


#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64
#define ONE 1
#define ZERO 0

char* _strcpy(char* destination, const char* source);
int _strlen(const char *string);
int _strncmp(const char* str1, const char* str2, size_t num);
char* _getenv(const char* name);
int _puts(const char* str);
char* _strchr(const char* str, int c);
int _strlen(const char *string);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strdup(const char *str);
char* _strcat(char* destination, const char* source);
char* read_input();
void tokenize_input(char *input, char **tokens, int *num_tokens);
char* find_command_path(char *command, char **envp);
void free_tokens(char **tokens);
void execute_command(char **tokens, int num_tokens, char **envp, char **argve);
int main(int argc, char **argv, char **envp);



#endif
