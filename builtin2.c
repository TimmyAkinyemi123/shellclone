#include "shell.h"

/**
 * my_history - Show history
 * @inf: arg
 * Return: 0
*/

int my_history(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * unset_alias - unsets alias
 * @inf: stryct
 * @s: string alias
 * Return: 0
*/

int unset_alias(info_t *inf, char *s)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_pos(&(inf->alias),
			get_node_pos(inf->alias, node_starts_with(inf->alias, s, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - Sets string alias
 * @inf: parameter syruct
 * @s: string alias
 * Return: 0
*/


int set_alias(info_t *inf, char *s)
{
	char *p;

	p = _strchr(s, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(inf, s));
	unset_alias(inf, s);
	return (add_node_end(&(inf->alias), str, 0) == NULL);
}

/**
 * print_alias - Prints an alias
 * @node: alias node
 * Return: 0
*/

print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '+');
		for (a = node->str; a <= p; a++)
			_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - mimics alias
 * @inf: struct
 * Return: 0
*/

int my_alias(info_t *inf)
{
	char *p = NULL;
		list_t *node = NULL;

	if (inf->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (int i = 1; inf->argv[i]; i++)
	{
		p = _strchr(inf->argv[i], '=');
		if (p)
			set_alias(inf, inf->argv[i];);
		else
			print_alias(node_starts_with(inf->alias, inf->argv[i], '='));
	}
			return (0);
}
