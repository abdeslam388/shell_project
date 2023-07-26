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
 * Hello_message - Writes "Hello, ALX!" 
 */
void Hello_message(void)
{
	write(STDOUT_FILENO, "Hello, ALX!\n", 14);
}

/**
 * main - Entry point 
 *        Calls the -mfunction to print the greeting.
 *
 */
int main(void)
{
	Hello_message();
	return (0);
}
