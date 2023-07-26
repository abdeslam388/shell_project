#include "shell.h"

/**
 * interactive - intection mode
 * @info: structure addr
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimt - check s'il y a un character delimiter
 * @c:charachter
 * @del: delimiter
 */
int is_delimt(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}

/**
 * _alpha - check pour les alphabets
 * @c: character
 */

int _alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _stin - conventions d'un string a un entier
 * @s: un string
 */

int _stin(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

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

