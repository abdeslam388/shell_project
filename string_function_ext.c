#include "shell.h"
/**
**strncpy- copier un string
*@dest:La destination de string d'etre y copier
*@src: la source du string
*@n: nombre de lettre a etre copier*/
char *_strncpy(char *dest, char *src, int n)
{
	int i, k;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		k = i;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}
/**
 **_strncat - concatenates deux "strings"
 *@dest:  first one
 *@src:  second one
 *@n:  nombre de bytes maximal a utiliser
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, k;
	char *s = dest;

	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while (src[k] != '\0' && j < n)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	if (k < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - Localiser un character dans un string
 *@s:  string to be parsed
 *@r: character to search
 */
char *_strchr(char *s, char *r)
{
	do {
		if (*s == r)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

