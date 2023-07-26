#include "shell.h"

/**
 * _memset - remplire la  memoire avec une constante' byte'
 * @p: pointer to the memo area
 * @t: byte to fill @s with
 * @n: amount of bytes in need to be filled
 */
char *_memset(char *p, char t, unsigned int n)
{
	unsigned int i;
    for (i = 0; i < n; i++)
	s[i] = t;
	return (p);
}

/**
 * ffree - liberez un string 
 * @ss: the str of the others
 */
void ffree(char **ss)
{
	char **c = ss;
	if (!ss)
	return;
	while (*ss)
	free(*ss++);
	free(c);
}

/**
 * _realloc - the re-location of the block of memo
 * @pt: pointer to the last malloc'ated block
 * @old_sz: byte sz of last block
 * @new_sz: byte sz of new one
 */
void *_realloc(void *pt, unsigned int old_sz, unsigned int new_sz)
{
	char *c;
	if (!pt)
	return (malloc(new_sz));
	if (!new_sz)
	return (free(pt), NULL);
	if (new_sz == old_sz)
	return (pt);
	c = malloc(new_sz);
	if (!c)
	return (NULL);
	old_sz = old_sz < new_sz ? old_sz : new_sz;
	while (old_sz--)
	c[old_sz] = ((char *)pt)[old_sz];
	free(pt);
	return (c);
}

