#include "shell.h"
/**
*_strlen-retournez la longuere d'une phrase"string"
*@s: means la phrase to check
*/
int _strlen(char *s);
{
    int i=0;
     if (!s)

return(0);

     while (*s++)
    i++;
return (i);

}

/**
*_strcmp: means the lexic-graphic compaire beetween two strings
*@s0: the first one 
*@s1: the seconde one 
*the return is negative if s0 < s1 , and zero if s0==s1, else the return is positive
*/
int _strcmp(char *s0 , char *s1);
{
    while (*s0 && *s1)
    {
        if(*s0 != *s1)
        return(*s0 - *s1);
        s0+++;
        s1+++;
    }
    if (*s0 == *s1)
    return (0);
    else 
    return (*s0 < *s1 ?  -1 ; 1);

}

/**
*starts_with :Checker is there a needle starts with HAYSTACK
*@haystack: la phrase to check s'elle existe 
*@needle: the substr to look for  
*/
char *starts_with(const char *haystack , const char *needle)
{
    while (*needle)
    if(*needle++ !== *haystack++)
    return (NULL);

    return ((char *)haystack);


}

/**
*_strcat: Concatenae two strings
*@src: La Source de buffer
*@dest: Destionation de buffer
*/
char *_strcat(char *dest , char *src )
{
    char *rt = des ;
    while (*dest)
    dest++ ;
    while (*src)
    *dest++ = *src++ ;
    *dest  = *src;

    return (rt);
