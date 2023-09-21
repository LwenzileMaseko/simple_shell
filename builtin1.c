#include "shell.h"

/**
 * unset_Alias - sets the alias to the string.
 * @info:THE parameter struct.
 * @str: string alias.
 *
 * Return: Always return 0 on success, 1 on error
 */
int unset_Alias(info_t *info, char *str)
{
	char *p, k;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	k = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = k;
	return (ret);
}

/**
 * print_Alias -It prints the  alias string.
 * @node: Alias node.
 *
 * Return: Always return 0 on success, 1 on error
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
 * set_Alias -It sets an alias to the string.
 * @info:The parameter struct.
 * @str: string alias.
 *
 * Return: Always return 0 on success, 1 on error
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
 * _mehistory - shows history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure with potential arguments. Maintain
 *        constant function prototype.
 *  Return: Always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * _mealias - copies alias builtin (man alias)
 * @info: Structure with potential arguments. Maintains
 *          constant function prototype.
 *  Return: Always return 0
 */
int _myalias(info_t *info)
{
	int k = 0;
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
	for (k= 1; info->argv[k]; k++)
	{
		p = _strchr(info->argv[k], '=');
		if (p)
			set_Alias(info, info->argv[k]);
		else
			print_Alias(node_starts_with(info->alias, info->argv[k], '='));
	}

	return (0);
}


