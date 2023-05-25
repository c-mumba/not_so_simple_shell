#include "main.h"

/**
 * read_user_input- Short description, single line
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
char *read_user_input(void)
{
	char *user_input;
	size_t n = 0;
	int bytes_read = 0;

	user_input = (char *)malloc(3);

	if (user_input == NULL)
		return (NULL);
	bytes_read = getline(&user_input, &n, stdin);
	if (bytes_read == -1)
		return (NULL);
	if (_strcmp(user_input, "\n", 0))
	{
		free(user_input);
		return (NULL);
	}
	free(user_input);
	return (user_input);
}

/**
 * parse_user_input - Short description, single line
 * @_inputs: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
char **parse_user_input(char *_inputs)
{
	char _input[_strlen(_inputs)];
	char *copy_input, *s1, *token, *token2;
	const char *delim = " \n";
	int counter = 0, i = 0, z = 0;
	char **list_of_tokens;

	strcpy(_input, _inputs);
	copy_input = (char *)malloc((_strlen(_input)) * sizeof(char));
	if (copy_input == NULL)
		return (NULL);

	strcpy(copy_input, _input);
	token = strtok(_input, delim);
	s1 = _strdup(token);

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
		list_of_tokens[i] = (char *)malloc(_strlen(token2) * sizeof(char));
		strcpy(list_of_tokens[i], token2);
		token2 = strtok(NULL, delim);
	}
	if (counter >= 2)
	{
		list_of_tokens[2] = NULL;
		list_of_tokens[0] = s1;
	}
	free(list_of_tokens);
	return (list_of_tokens);
}

/**
 * commandPath- Short description, single line
 * @command: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
char *commandPath(char *command)
{
	char *path, *copy_path, *path_token, *command_path, *_exit = "exit";
	char *pr = "bash: %s: command not found\n";
	const char *delim = ":";
	struct stat buf;
	char *ll[] = {"exit", "99", NULL};

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
			path_token = strtok(NULL, delim);
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
	exit(0);
	return (NULL);
}
/**
 * builtin_exit- Short description, single line
 * @list_tokens: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
int builtin_exit(char **list_tokens)
{
	int i, err_no = 0;

	if (strtok(list_tokens[1], " \n") == NULL)
		exit(0);
	if (list_tokens[1] != NULL)
	{
		for (i = 0; list_tokens[1][i]; i++)
			if ((list_tokens[1][i] < '0' || list_tokens[1][i] > '9')
					 && list_tokens[1][i] != '+')
			{
				errno = -1;
				return (-1);
			}
		err_no = _atoi(list_tokens[1]);
	}
	exit(errno);
}
/**
 * builtin_env- Short description, single line
 * @envp: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
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

