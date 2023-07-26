#include "shell.h"

/**
 * _myenv - affichez l'envirenement actuelle
 * @info: Structure 
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_env - avoir la valeure d'un envirens variable
 * @info: Structure 
 * @name: environ ou variable naom
 */
char *get_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *c;

	while (node)
	{
		c = starts_with(node->str, name);
		if (c && *c)
			return (c);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - intialisation du noveau environs variable 
 * @info: Structure
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_mysetenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - eliminez un environs variable
 * @info: Structure 
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_myunsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - pop linkedlists
 * @info: Structure 
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t s;

	for (s = 0; environ[s]; s++)
		add_node_end(&node, environ[s], 0);
	info->env = node;
	return (0);
}


