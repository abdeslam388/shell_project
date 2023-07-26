#include "shell.h"

/**
 * grid_free- free griddd
 * @gridd: Char double ptrr freed
 * @_height: int for heightes to be passed
 * Return: void
 */
void grid_free(char **gridd, int height)
{
	int k;

	for (k = 0; k < height; k++)
		free(gridd[k]);

	free(gridd);
}


/**
 * no_nul - remov  new line using NULL charr
 * @l:   c_linn
 * Return: nothhing
 */
void no_nul(char *l)
{

	int i = 0;

	while (l[i])
	{
		if (l[i] == '\n')
		{
			l[i] = '\0';
			return;
		}

		i++;
	}
}


/**
 * char_special - exits   shell and handles
 * @byt:   nbr of byt read from  inpt
 * @buffer:   burffer char
 * @exit_st:   exit status
 * Return: 0 succcess
 */
int  char_special(char *buffer, ssize_t byt, int *exit_st)
{
	int i = 0;

	if (byt == EOF && isatty(STDIN_FILENO) == 1)
	{
		put_char('\n');
		free(buffer);
		exit(*exit_st);
	}

	if (byt == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(buffer);
		exit(*exit_st);
	}

	if (str_cmp(buffer, "\n") == 0)
	{
		*exit_st = 0;
		return (127);
	}

	while (buffer[i] != '\n')
	{
		if (buffer[i] != ' ' && buffer[i] != '\t')
			return (0);

		++i;
	}

	*exit_st = 0;
	return (127);
}
