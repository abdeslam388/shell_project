#ifndef _shell_h
#define _shell_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/*betty.c*/
void Hello_message(void);
int char_special(char *line, ssize_t read, int *exit_stat);
void no_nul(char *line);
char **_parser(char *line);
void built_ins(char *line, char **args, char **env, int *exit_stat);
int my_path(char *cmd, char **args, char **env, int *exit_stat);
void exec_env(int status, char **args, int *exit_stat, int *tall);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/* red - wrt les  buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define VRAI (1 == 1)

/* my_path  functions that i neeed*/
int my_path(char *yfirst, char **inpt, char **env, int *exit_st);


/* env fct */
int print_env(char **env, int *exit_st);
char *cpy_env(char **env);

/* built- execute functions */
void built_ins(char *c_lin, char **args, char **env, int *exit_st);
void exec_env(int status, char **args, int *exit_st, int *taly);



/* strings handller function  */
int str_len(char *s);
char *str_dup(char *strg);
int str_cmp(char *s0, char *s1);
char *str_cpy(char *dstn, char *sourc);
char *str_cat(char *dstn, char *sourc);



/* print.c functions  */
int put_char(char ch);
void printstr_(char *st);
char *path_str(char *p_right, char *xfirst);
char **_parser(char *l);
void print_int(int *taly);


/* char handler functions */
void no_nul(char *l);
void grid_free(char **gridd, int _height);
int char_special(char *buffer, ssize_t byt, int *exit_st);


/*_getline function*/

ssize_t _getline(char **line, size_t *n, FILE *stream);
char *str_tok(char *str, const char *delimiters);

/* reallooc  functions */
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *destination, const void *src, size_t size);
int _getsize(const char *str);


/* affichage functions */
void _puts(const char *str);
int _putchar(char c);

/*setenv and unsetenv*/
void _setenv(char **arr);
void _unsetenv(char **arr);
char *get_env(const char *glob_v);
char *concatenat(char *glob_v, char *valeur1, char *valeur);

extern char **environ;

#endif
