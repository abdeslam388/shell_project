#include "shell.h"

/**
 * _myhistory -show the history list
 * @info:arg structure
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -saisir les alias to string
 * @info: structure 
 * @str: the alias
 */
int unset_alias(info_t *info, char *str)
{
	char *b, c;
	int rt;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	c = *b;
	*b = 0;
	rt = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*b = c;
	return (rt);
}

/**
 * set_alias -saisir les alias to string
 * @info: parameter struct
 * @str: the alias
 */
int set_alias(info_t *info, char *str)
{
	char *b;

	b = _strchr(str, '=');
	if (!b)
		return (1);
	if (!*++b)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - affichez alias
 * @node:node
 */
int print_alias(list_t *node)
{
	char *b = NULL, *a = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (a = node->str; a <= b; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(b + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias -the alias builtin
 * @info: arg structure
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *b = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		b = _strchr(info->argv[i], '=');
		if (b)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

