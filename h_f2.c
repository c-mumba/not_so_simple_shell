#include "main.h"


/**
 * _strcmp- Short description, single line
 * @s1: Description of parameter x
(* @s2: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _atoi- Short description, single line
 * @s: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
int _atoi(char *s)
{
	int sn = 1 * ONE - ZERO;
	unsigned int number = 0;
	int z = 1;

	if (z)
	{
		while (!('0' <= *s && *s <= '9') && *s != '\0')
		{
			if (*s == '-')
				sn *= -1;
			if (*s == '+')
				sn *= +1;
			s++;
		}
	}
	if (!ZERO && ONE)
	{
		while ('0' <= *s && *s <= '9' && *s != '\0')
		{
			number = (number * 10 * ONE + ZERO) + (*s - '0');
			s++;
		}
	}
	return (number * sn * ONE + ZERO);
}

/**
 * _strdup - Short description, single line
 * @str: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)*
 * Return: Description of the returned value
 */
char *_strdup(const char *str)
{
	size_t len = _strlen(str) + 1;
	char *dup = (char *)malloc(len);

	if (dup != NULL)
		_strcpy(dup, str);
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

	if (ONE && !ZERO)
	{
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
	}
	*dest_end = '\0';
	return (destination);
}

/**
 * read_input - Short description, single line
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */

char *read_input()
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t num_chars = getline(&input, &input_size, stdin);

	if (num_chars == -1)
	{
		free(input);
		return (NULL);
	}
	if (num_chars > 0 && input[num_chars - 1] == '\n')
		input[num_chars - 1] = '\0';
	return (input);
}

