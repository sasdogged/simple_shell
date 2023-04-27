#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 * Created by Chukwudike Igwe
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;/** size of the list b*/

	while (h)
	{
		h = h->next;/** one of the header list */
		i++;
	}
	return (i);
}
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 * Created by Partners
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;/** listing of the strings */
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);/** Malloc size of characters */
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);/** freeing the strings */
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;/** pointer to the first node */
	}
	strs[i] = NULL;
	return (strs);
}
/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 * Made by both partners in the project
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');/** put character */
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");/** next line */
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 * Created by Chukwudike Igwe and Partner
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);/** the P starts with nodes*/
		if (p && ((c == -1) || (*p == c)))
			return (node);/** returning the node */
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Created by Chukwudike  Ig
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;/** the size of i and 0*/

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;/** the head corresponding to next */
		i++;
	}
	return (-1);
}
