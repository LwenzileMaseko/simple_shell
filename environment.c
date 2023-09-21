#include "shell.h"

/**
 * _myunsetenv - deletes environment variable
 * @info: Structure with potential arguments. Maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _myunsetenviron(info_t *info)
{
	int k;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (k = 1; k <= info->argc; k++)
		_unsetenv(info, info->argv[k]);

	return (0);
}

 /**
 * _getenviron - retrive the value of an environ variable
 * @info: Structure with potential arguments. Maintains
 * constant funcction prototype.
 * @name: environ var name
 *
 * Return: value
 */
char *_getenviron(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myenviron - print current environ
 * @info: Struct with potential arguments. Maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenviron(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _mysetenviron - makes initial a new environment variable,
 *             or modifies an existing one
 * @info: Structure with potential arguments. Maintains
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenviron(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * populate_environ_list -makes env linked list populated
 * @info: Structure with potential arguments. Maintains
 *          constant function prototype.
 * Return: Always 0
 */
int populate_environ_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}

