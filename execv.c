#include "shell.h"

/**
 * built_ins - implementtxx builtins
 * @c_lin:   buffer command line
 * @args:   parsed agsd
 * @env:   envv de varriable
 * @exit_st:   exit
 * Return: voiid
 */
void built_ins(char *c_lin, char **args, char **env, int *exit_st)
{

	if (str_cmp(args[0], "exit") == 0)
	{
		free(args);
		free(c_lin);
		exit(*exit_st);
	}

	if (str_cmp(args[0], "env") == 0)
		print_env(env, exit_st);
}

/**
 * exec_env - executed in   main
 * @status:   status of   path wenn file is executable
 * @args:  parsed argss
 * @exit_st:   exit staatus
 * @taly: tally of commaands or attempted commands that were run
 * Return: void
 */
void exec_env(int status, char **args, int *exit_st, int *taly)
{
	if (status == 2)
	{
		if (access(args[0], X_OK) == 0)
		{
			if (fork() == 0)
				execve(args[0], args, NULL);

			else
				wait(NULL);
			*exit_st = 0;
		}
		else if (access(args[0], F_OK) != 0)
		{
			printstr_("sh: ");
			print_int(taly);
			printstr_(": ");
			perror(args[0]);
			*exit_st = 127;
		}
		else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
		{
			printstr_("sh: ");
			print_int(taly);
			printstr_(": ");
			perror(args[0]);
			*exit_st = 126;
		}
	}
	free(args);
}
