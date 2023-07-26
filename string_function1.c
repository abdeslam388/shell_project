#include "shell.h"
/**
*_strcpy : copier un 'string '
*@dest :La  Destination
*@src : La source
*/
char *_strcpy(char *dest , char *src)
{
    int i=0;
    if(dest == src || src =0)
    return (dest);
    while (src[i])
    {
        dest[i] = src [i];
        i++;
    }
    dest[i]=0;


    return(des);
}


/**
*_strdup : duplicate un string 
*@str: string needed to be duplicated
*/
char *_strdup (const char *str)
{
    int leng = 0 ;
    char *rloc ;
    if (str == NULL)
    return (NULL);
    while (*str++)
    leng++;
    rloc = malloc(sizeof (char) * (leng + 1));
    if (!rloc)
    return(NULL);
    for (leng++; leng--;)
    rloc[leng] = *--str;
    return (rloc);

}


/**
*_putchar: Ecrire le charactere @c au stdout
*@c: The character needed to be printed
*/
int _putchar(char c)
{
    static int i ;
    static char buf[WRITE_BUF_SIZE];
     
     if (c==BUF_FLUSH || i>=WRITE_BUF_SIZE)
     {
        write(1 , buf , i);
        i=0;
     }
     if ( c != BUF_FLUSH)
     buf[i++] =  c;
     return (1);
}

/**
*_puts : print input string
* @str : string
*/
void _puts (char *str)
{
int i=0;
if (!str)

return;

while (str [i] != '\0')
{
     _putchar(str[i]);
     i++
}
}

