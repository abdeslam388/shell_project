#include "shell.h"

/**
 * _puts - printf the string.
 * @str: strings too printf.
 * Return: null.
 */

void _puts(const char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
