#include "shell.h"

/**
 * list_len - determinez la languere d'une liste
 * @h: pointeure du premier neux
 */
size_t list_len(const list_t *h)
{
	size_t s = 0;

	while (h)
	{
		h = h->next;
		s++;
	}
	return (s);
}

/**
 * list_to_strings - returnez un tableux de  list->str
 * @head: pointeure du premier neux
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t s = list_len(head), j;
	char **strr;
	char *str;

	if (!head || !s)
		return (NULL);
	strr = malloc(sizeof(char *) * (s + 1));
	if (!strr)
		return (NULL);
	for (s = 0; node; node = node->next, s++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < s; j++)
				free(strr[j]);
			free(strr);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strr[s] = str;
	}
	strr[s] = NULL;
	return (strr);
}


/**
 * print_list - affichez les element d'une liste
 * @h: pointeure du premier neux
 */
size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - retournez les string qui debut par un prefix
 * @node: pointeur de tete
 * @prefix: string to check
 * @c: carachtere
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *t = NULL;

	while (node)
	{
		t = starts_with(node->str, prefix);
		if (t && ((c == -1) || (*t == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - have an index 
 * @head: pointeur du list 
 * @node: pointeure du neux
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t s = 0;

	while (head)
	{
		if (head == node)
			return (s);
		head = head->next;
		s++;
	}
	return (-1);
}

