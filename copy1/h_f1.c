#include "main.h"

/**
 * _strdup - Short description, single line
 * @str: Description of parameter x
 * @Description: Longer description of the function)?
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
 * _strcat - Short description, single line
 * @destination: Description of parameter x
(* @source: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *_strcat(char *destination, const char *source)
{
	char *dest_end = destination;
	const char *src_end = source;

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
 * _strncmp - Short description, single line
 * @str1: Description of parameter
 * @str2: Description of parameter
 * @num: Description of parameter
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
int _strncmp(const char *str1, const char *str2, size_t num)
{
	size_t i;
	for (i = 0; i < num; i++)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		if (str1[i] == '\0')
			return (0);
	}
	return (0);
}

/**
 * _getenv - Short description, single line
 * @name: Description of parameter x
(* Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *_getenv(const char *name)
{
	int i;
	extern char **environ;
	size_t nameLen = _strlen(name);

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, nameLen) == 0 && environ[i][nameLen] == '=')
		{
			return (environ[i] + nameLen + 1);
		}
	}
	return (NULL);
}

/**
 * _strcpy - Short description, single line
 * @destination: Description of parameter x
(* @source: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
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

