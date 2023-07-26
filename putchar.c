#include "shell.h"
/**
*_putchar - Ecrire le charactere @c au stdout
*@c : The character needed to be printed
Return: 1 On success.
*/

int _putchar(char c)
{
		return (write(1, &c, 1));
}

/**
*str_print - print input string
*@str: string nedded to be print
*/

void str_print(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
