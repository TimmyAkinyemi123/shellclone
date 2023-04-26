#include "shell.h"

/**
 * Interactive - Checks if in interactive mode
 * @inf: address
 * Return: 1 if imteractive
*/

int Interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_Delim - Checks for delikmiter
 * @c: Char to check
 * @delim: DElimiter string
 * Return: 1 if true
*/

int is_Delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Checks for alphabets
 * @c: Char
 * Return: 1 if alphabet
*/
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts str to int
 * @s: string
 * Return: 0 if no num in string
**/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (int i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '_')
			sign = -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
