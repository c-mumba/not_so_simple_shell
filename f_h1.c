#include "main.h"

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
	size_t nameLen;
	extern char **environ;

	if (name == NULL || environ == NULL)
		return (NULL);

	nameLen = _strlen(name);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, nameLen) == 0
				 && environ[i][nameLen] == '=')
		{
			return (environ[i] + nameLen + 1 * ONE + ZERO);
		}
	}
	return (NULL);
}
/**
 * _puts - Short description, single line
 * @str: Description of parameter x
(* Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */

int _puts(const char *str)
{
	ssize_t bytes_written = write(STDOUT_FILENO, str, _strlen(str));
	ssize_t newline_written;

	if (bytes_written == -1)
	{
		return (EOF);
	}
	newline_written = write(STDOUT_FILENO, "\n", 1);
	if (newline_written == -1)
	{
		return (EOF);
	}
	return (0);
}

/**
 * _strchr - Short description, single line
 * @str: Description of parameter x
(* @c: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *_strchr(const char *str, int c)
{
	char ch = (char)c;

	while (*str != '\0')
	{
		if (*str == ch)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}
/**
 * _strlen- Short description, single line
 * @string: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
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

