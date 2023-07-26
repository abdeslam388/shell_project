#include "shell.h"

/**
 * str_len - return lengeur of a str
 * @strgg: charrrr
 * Return: returns lengeur strg
 */
int str_len(char *strgg)
{
	int k = 0;

	while (strgg[k] != '\0')
		k++;

	return (k);
}


/**
*str_cmp- means the lexico-graphic compaire between two strings
*@s0: the firsttt one
*@s1: the secondde
*return: successs
*/
int str_cmp(char *s0, char *s1)
{

	while (*s0)
	{
		if (*s0 != *s1)
			break;
		s0++;
		s1++;
	}
	return (*s0 - *s1);
}


/**
 * str_cpy - copy la chaine
 * @dstn: string ber 1
 * @sourc: string nbr 2
 * Return: string copiied final
 */
char *str_cpy(char *dstn, char *sourc)
{
	int a;

	for (a = 0; a <= str_len(sourc); a++)
		dstn[a] = sourc[a];
	return (dstn);
}


/**
 * str_dup - function returns ptr to a new alllocation contains a chaine
 * @strg: - Char strg to coppy
 * Return: Char ptr to   duplicated mew char. or NULL
 * if no memory find
 */

char *str_dup(char *strg)
{
	char *dpstr;

	int i, l;

	if (strg == NULL)
		return (NULL);

	l = 0;

	for (i = 0; strg[i] != '\0'; i++)
		l++;

	dpstr = malloc(sizeof(char) * l + 1);

	if (dpstr == NULL)
		return (NULL);

	for (i = 0; i < l ; i++)
		dpstr[i] = strg[i];

	dpstr[l] = '\0';

	return (dpstr);

}


/**
 * str_cat - concatination de chaine de caractaire
 * @dstn: strg first one
 * @sourc: string ssecande one
 * Return: concat la chaine
 */
char *str_cat(char *dstn, char *sourc)
{
	int len = str_len(dstn);
	int i;

	for (i = 0; sourc[i] != '\0'; i++)
		dstn[len + i] = sourc[i];
	dstn[len + i] = '\0';

	return (dstn);
}
