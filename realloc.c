#include "shell.h"

/**
 * _memcpy - do copy to the chaine de charactire and check it.
 * @des: pr pointer.
 * @src: ds pointer.
 * @size: siize memory.
 * Return: destination.
 */
void *_memcpy(void *des, const void *src, size_t size)
{
	unsigned char *d = (unsigned char *)des;
	const unsigned char *s = (const unsigned char *)src;
	size_t i;

	for (i = 0; i < size; i++)
	{
		d[i] = s[i];
	}

	return (des);
}

/**
 * _getsize - return size de str.
 * @str: pointer.
 * Return: size in a endd.
 */
int _getsize(const char *str)
{
	int size = 0;

	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

/**
 * _realloc - the realocation of the block of realloc call
 * @ptr: pointer to the last malloc'ated block
 * @size: memory sizzze.
 * Return: new ptr.
 */

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t old_size, copy_size;

	old_size = _getsize(ptr);
	copy_size = (old_size < size) ? old_size : size;
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = _memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
