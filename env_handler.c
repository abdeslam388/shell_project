#include "shell.h"

/**
 * my_path - function that print envment  position  OR th PATH
 * @env: envment variables
 * @xfirst: first spliite into tokns with inpttted args
 * @inpt:   input is spllit into tokens
 * @exit_st:   exit statusss
 * Return: FAUX
 */
int my_path(char *yfirst, char **inpt, char **env, int *exit_st)
{
	int i;
	char *temp, *p_left, *p_right;
	char *new = NULL, *env_cp = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		env_cp = str_dup(env[i]);
		p_left = strtok(env_cp, "= \t");
		temp = strtok(NULL, "= \t");

		if (str_cmp(p_left, "PATH") == 0)
		{
			p_right = strtok(temp, ": \t");
			while (p_right)
			{
				new = path_str(p_right, yfirst);

				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
						execve(new, inpt, NULL);

					else
						wait(NULL);
					*exit_st = 0;
					free(new);
					free(env_cp);
					return (0);
				}
				p_right = strtok(NULL, ": \t");
				free(new);
			}
		}
		free(env_cp);
	}
	return (2);
}

/**
 * print_env - printt env variable that u find 
 * @env:   env variablle to print
 * @exit_st: exit statuss
 * Return:  0 is success
 */
int print_env(char **env, int *exit_st)
{
	unsigned int i = 0;

	while (env[i] != NULL)
	{
		printstr_(env[i]);
		put_char('\n');
		i++;
	}
	*exit_st = 0;
	return (EXIT_SUCCESS);
}
