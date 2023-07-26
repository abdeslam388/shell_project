#include "shell.h"
#define _ISOC99_SOURCE

/**
 * is_delim - check if  there a dellimter.
 * @c: char to check if exist.
 * @delim: the delimiter i want.
 * Return: if delim gives vrai, if not give false.
 */
unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - spliiting a string.
 * @srcString: string to split we want.
 * @delim: sepparator.
 * Return: splited strings im end.
 */
char *_strtok(char *srcString, char *delim)
{
	static char *backup_string;
	char *ret;

	if (!srcString)
		srcString = backup_string;
	if (!srcString)
		return (NULL);

	while (1)
	{
		if (is_delim(*srcString, delim))
		{
			srcString++;
			continue;
		}

		if (*srcString == '\0')
			return (NULL);
		break;
	}

	ret = srcString;

	while (1)
	{
		if (*srcString == '\0')
		{
			backup_string = srcString;
			return (ret);
		}
		if (is_delim(*srcString, delim))
		{
			*srcString = '\0';
			backup_string = srcString + 1;
			return (ret);
		}
		srcString++;
	}
}

/**
 * split_string - check myy code.
 * @str: string to split i wanr.
 * @delimiter: char del.
 * Return: splited stringg.
 */
char **split_string(char *str, char *delimiter)
{
	char **ptr_token;
	char *token;
	int i = 0;

	ptr_token = malloc(sizeof(char *) * 1024);
	token = _strtok(str, delimiter);
	while (token)
	{
		ptr_token[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	ptr_token[i] = NULL;
	return (ptr_token);
}
