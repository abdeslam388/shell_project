#include "shell.h"

/**
 * bfree - Libère un pointeur et "NULL" l'adresse
 * @ptr: The add of pointer needed to be to free
 */
int bfree(void **pt)
{
	if (pt && *pt)
	{
	free(*pt);
	*pt= NULL;
	return (1);
	}
	return (0);
}
