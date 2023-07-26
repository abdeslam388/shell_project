#include "shell.h"

/**
 * is_chain - testz si la cheine acctuelle du buffer is a delimiters
 * @buf: the char buffer
 * @p: address of current position in buf
 * @info: the parameter struct
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* trouver la fin de ctte command  */
	{
		buf[j] = 0; /* remplacez les semi-colones par c*/
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}

/**
 * check_chain - checker
 * @len: langeure du buff
 * @buf: the char buffer
 * @p: addr
 * @i: start pos
 *@info: structure
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - remplacez un alias dans le tokenizer string
 * @info: t structure
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *t;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		t = _strchr(node->str, '=');
		if (!t)
			return (0);
		t = _strdup(p + 1);
		if (!t)
			return (0);
		info->argv[0] = t;
	}
	return (1);
}

/**
 * replace_virs - replaces virs in tokenized 
 * @info: leparametre structure
 */
int replace_virs(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - remplacez un string
 * @old: addr d'ancienne phrase
 * @new: nouvelle phrase
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}


