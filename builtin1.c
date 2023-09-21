#include "shell.h"


/**
 * set_Alias - set alias will be set on string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: 0 always on success, 1 on error
 */
int set_Alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (set_Alias(info, str));

	set_Alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * _mehistory - shows history list, one command a line, preceded
 *              with numbered lines,beginning at 0.
 * @info: Structure with potential arguments. Maintains
 *        constant function prototype.
 *  Return: Always 0
 */
int _mehistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_Alias - alias is set to string
 * @info: parameter struct
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_Alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * print_Alias - shows an alias string
 * @node: an alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_Alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _mealias - copies the alias builtin (man alias)
 * @info: Structure with potential arguments. Maintains
 *          constant function prototype.
 *  Return: Always 0
 */
int _mealias(info_t *info)
{
	int y = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_Alias(node);
			node = node->next;
		}
		return (0);
	}
	for (y = 1; info->argv[y]; y++)
	{
		p = _strchr(info->argv[y], '=');
		if (p)
			set_Alias(info, info->argv[y]);
		else
			print_Alias(node_starts_with(info->alias, info->argv[y])'=');
	}

	return (0);
}

