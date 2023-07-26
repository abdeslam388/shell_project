
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
 * Hello_message - Writes "Hello, World" in the output
 */
void Hello_message(void)
{
    write(STDOUT_FILENO, "Hello, World\n", 14);
}

/**
 * main - Entry point of the progme - Calls the Hello_message function
 */
int main(void)
{
    Hello_message();
    return 0;
}

