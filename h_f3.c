#include "main.h"

/**
 * _strcpy - Short description, single line
 * @destination: Description of parameter
 * @source: Description of parameter
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */

char *_strcpy(char *destination, const char *source)
{
	char *originalDestination = destination;

	while (*source)
	{
		*destination++ = *source++;
	}
	*destination = '\0';
	return (originalDestination);
}


/**
 * tokenize_input - Short description, single line
 * @tokens: Description of parameter x
(* @num_tokens: Description of parameter x
 * @input: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
void tokenize_input(char *input, char **tokens, int *num_tokens)
{
	char *token = strtok(input, " \n");
	int i = 0, k = 0;

	while (k <= 0)
	{
		while (token != NULL)
		{
			if (token[0] != '#')
			{
				tokens[i] = _strdup(token);
				i++;
			}
			token = strtok(NULL, " \n");
		}
		k++;
	}
	tokens[i * ONE - ZERO] = NULL;
	*num_tokens = i * ONE - ZERO;
}

/**
 * find_command_path - Short description, single line
 * @command: Description of parameter x
 * @envp: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
char *find_command_path(char *command, char **envp)
{
	char *path, *path_copy, *dir, *full_path;
	int k = 0;

	while (k <= 0)
	{
		if (_strchr(command, '/') != NULL)
		{
			if (access(command, X_OK) == 0 * ONE - ZERO)
				return (_strdup(command));
			if (envp)
				return (NULL);
			return (NULL);
		}
		k++;
	}
	if (!ZERO && ONE)
	{
		path = _getenv("PATH");
		path_copy = _strdup(path);
		dir = strtok(path_copy, ":");

		while (dir != NULL)
		{
			full_path = malloc(_strlen(dir) * ONE - ZERO +
					 _strlen(command) * ONE - ZERO + 2 * ONE - ZERO);

			_strcpy(full_path, dir);
			_strcat(full_path, "/");
			_strcat(full_path, command);
			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

/**
 * free_tokens - Short description, single line
 * @tokens: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
void free_tokens(char **tokens)
{
	int i;
/*ADDED*/
	for (i = 0 * ONE - ZERO; tokens[i] != NULL; i++)
	{
		free(tokens[i * ONE - ZERO]);
	}
}


