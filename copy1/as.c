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
 * main - Short description, single line
 * @argv: Description of parameter x
(* @argc: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */


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



typedef struct builtins
{
	char *builtin;
	int (*function)(char **list_tokens);
} builtins;

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *_strdup(const char *str)
{
    size_t len = strlen(str) + 1;
    char *dup = (char *)malloc(len);

    if (dup != NULL)
    {
        strcpy(dup, str);
        }

    return (dup);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char* _strcat(char* destination, const char* source)
{
    char* dest_end = destination;
    const char* src_end = source;

    while (*dest_end != '\0')
    {
        dest_end++;
    }

    while (*src_end != '\0')
    {
         *dest_end = *src_end;
        dest_end++;
        src_end++;
    }
    *dest_end = '\0';
    return (destination);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int _strncmp(const char* str1, const char* str2, size_t num)
{
    size_t i;
    for (i = 0; i < num; i++) {
        if (str1[i] != str2[i])
            return ((int)(str1[i] - str2[i]));
        if (str1[i] == '\0')
            return (0);
    }
    return (0);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char* _getenv(const char* name) {
    int i;
    size_t nameLen;
    extern char** environ;
    if (name == NULL || environ == NULL)
        return (NULL);

    nameLen = _strlen(name);

    for (i = 0; environ[i] != NULL; i++) {
        if (_strncmp(environ[i], name, nameLen) == 0 && environ[i][nameLen] == '=') {

            return (environ[i] + nameLen + 1);
        }
    }
    return (NULL);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char* _strcpy(char* destination, const char* source)
{
    char* originalDestination = destination;

    while (*source) {
        *destination++ = *source++;
    }

    *destination = '\0';

    return (originalDestination);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
void copyStringList(char** dest, char** src, int size)
{
    int i;

    for (i = 0; i < size + 1; i++)
    {
        dest[i] = (char*)malloc(_strlen(src[i]) + 1);
        dest[i] = strdup(src[i]);
    }
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int getStringListLength(char** stringList)
{
    int length = 0;
    while (stringList[length] != NULL)
    {
        length++;
    }
    return (length);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int _strlen(const char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int _strcmp(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
    {
		if (_strlen(string1) != _strlen(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
    {
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int _atoi(char *s)
{
	int sn = 1;
	unsigned int number = 0;

    while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sn *= -1;
		if (*s == '+')
			sn *= +1;
		s++;
	}

    while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sn);
}


/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *read_user_input(void)
{
    char *user_input;
    size_t n = 0;
    int bytes_read = 0;

    user_input = (char *)malloc(3 * sizeof(char));

    bytes_read = getline(&user_input, &n, stdin);
    if (bytes_read == -1)
    {
        printf("Error, getline function didn't work!");
        return (NULL);
    }

    if (_strcmp(user_input,"\n", 0)){
    free (user_input);
    return (NULL);
    }

    free (user_input);
    return (user_input);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char **parse_user_input(char *_inputs)
{   int s = _strlen(_inputs);
    char *_input = (char *)malloc(s * sizeof (char));
    char *copy_input, *token, *token2;
    const char *delim = " \n";
    int counter = 0, i = 0;
    char **list_of_tokens;

    strcpy(_input, _inputs);
    copy_input = (char *)malloc((_strlen(_input)) * sizeof (char));

    if (copy_input == NULL)
    return (NULL);

    strcpy(copy_input, _input);

    token = strtok(_input, delim);
    /*s1 = _strdup(token);*/

    while (token != NULL)
    {
        token = strtok(NULL, delim);
        counter++;
    }

    list_of_tokens = (char **)malloc(sizeof(char *) * (counter));

    if (list_of_tokens == NULL)
    return (NULL);

    token2 = strtok(copy_input, delim);

    for (i = 0; token2 != NULL; i++)
    {
        list_of_tokens[i] = (char *)malloc(_strlen(token2) * sizeof (char));
        strcpy(list_of_tokens[i], token2);
        token2 = strtok(NULL, delim);
    }
/*     if (counter >= 2)
    {
        list_of_tokens[2] = NULL;
        list_of_tokens[0] = s1;
    } */
    free(list_of_tokens);
    return (list_of_tokens);
}

/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *commandPath(char *command)
{
    char *path, *copy_path, *path_token, *command_path;
    char *pr = "bash: %s: command not found\n";
    const char *delim = ":";
    struct stat buf;

    if (command == NULL)
    return (NULL);

    path = (char *)malloc(_strlen(_getenv("PATH")) * sizeof(char));

    if (path == NULL)
    return (NULL);

    path = _getenv("PATH");
    copy_path = _strdup(path);
    path_token = strtok(copy_path, delim);

    while (path_token != NULL)
    {
        command_path = (char *)malloc(_strlen(path_token) + _strlen(command) + 2);
        if (!command_path)
        return (NULL);

        _strcpy(command_path, path_token);
        _strcat(command_path, "/");
        _strcat(command_path, command);
        _strcat(command_path, "\0");

        if (stat(command_path, &buf) == 0)
        {
            free(command_path);
            return (command_path);
        }
        else
        {
            path_token = strtok(NULL, delim);
        }
    }
    free(copy_path);
    if (stat(command, &buf) == 0)
    {
        free(copy_path);
        free(path);
        free(command_path);
        return (command);
    }
    write(STDOUT_FILENO, pr, _strlen(pr));
    exit (0);
    return (NULL);
}
/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int builtin_exit(char **list_tokens)
{
    int i, err_no = 0;

    if (strtok(list_tokens[1], " \n") == NULL)
    exit (0);

    if (list_tokens[1] != NULL)
	{
        for (i = 0; list_tokens[1][i]; i++)

        if ((list_tokens[1][i] < '0' || list_tokens[1][i] > '9') && list_tokens[1][i] != '+')
			{
                errno = -1;
				return (-1);
			}
		err_no = _atoi(list_tokens[1]);
	}
    exit(err_no);
}
/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int builtin_env(char **envp)
{
    int i;
    if (!envp)
    return (-1);

    for (i = 0; envp[i]; i++)
    {
        write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    return (1);
}
/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int builtins_list(char **list_tokens, char **envp)
{
    int iterator;
    char enp[] = "env";
	builtins options[] = {
		{"exit", builtin_exit},
		{"env", builtin_env},
        {NULL, NULL}
	};

    for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
        if (_strcmp(options[iterator].builtin, list_tokens[0], 0))
		{
            if (_strcmp(options[iterator].builtin, enp, 0))
            {
                return (options[iterator].function(envp));
            }
            else
			return (options[iterator].function(list_tokens));
		}
    }
	return (-1);
}
/**
 *  - Short description, single line
 * : Description of parameter x
(* : Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int execute(char **list_tokens, char **LT, char **en)
{
    pid_t pid;
    char *spp[] = {"ls",NULL};
    char *first = strtok(LT[0], " \n");
    int stat, size = getStringListLength(list_tokens);

    if (!list_tokens)
        return (0);
    pid = fork();

    if (pid == -1)
        perror("Fork error");
    else if (pid == 0)
    {
        if (size > 1)
        {
            if (execve(commandPath(first), list_tokens, en) == -1)
                perror("Error with execution");
        }
        else
        {
            if (execve(commandPath(first), spp, en) == -1)
                perror("Error with execution");
        }
    }
    else
    {
            if (waitpid(pid, &stat, 0) > 0)
            {
                if (WIFEXITED(stat) && !WEXITSTATUS(stat))
                    return (0);
                return (0);
            }
    }
    return (0);
}

void inf_loop(char **envp)
{
    char *user_input;
    char **list_tokenss;
    int state;
    char *prompt = "$ ";
do
    {
        state = isatty(STDIN_FILENO);
        write(STDOUT_FILENO, prompt, _strlen(prompt));
        user_input = read_user_input();

        if (user_input)
        {
            list_tokenss = parse_user_input(user_input);
            if (builtins_list(list_tokenss,envp) >= 0)
            {

            }

            else
            {
                execute(list_tokenss, list_tokenss, envp);
            }
        }
    }
    while (state == 1);
}

int main(int argc, char *argv[], char *env[])
{
    inf_loop(env);

    if (!argc || !argv)
    return (0);
    else
    return (0);

}

