#include "main.h"

/**
 * copyStringList- Short description, single line
 * @dest: Description of parameter x
(* @src: Description of parameter x
 * @size: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
void copyStringList(char **dest, char **src, int size)
{
	int i;

	for (i = 0; i < size + 1; i++)
	{
		dest[i] = (char *)malloc(_strlen(src[i]) + 1);
		dest[i] = strdup(src[i]);
	}
}

/**
 * getStringListLength- Short description, single line
 * @stringList: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
 * Return: Description of the returned value
 */
int getStringListLength(char **stringList)
{
	int length = 0;

	while (stringList[length] != NULL)
	{
		length++;
	}
	return (length);
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

/**
 * _strcmp- Short description, single line
 * @string1: Description of parameter x
(* @string2: Description of parameter x
 * @number: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
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
 * _atoi- Short description, single line
 * @s: Description of parameter x
 * Description: Longer description of the function)?
(* section header: Section description)
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

