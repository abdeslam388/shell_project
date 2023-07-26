#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/**
 * Hello_message - Writes "Hello, ALX!" to the std output.
 */
void Hello_message(void)
{
	write(STDOUT_FILENO, "Hello, ALX!\n", 14);
}

/**
 * main - Entry point of the progra
 *
 * Return: 0 to me
 */
int main(void)
{
	Hello_message();

	return (0);
}
