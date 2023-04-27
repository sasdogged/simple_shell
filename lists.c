#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Created by Chukwudike Igwe
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));/** new malloc size of lists */
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;/** new head num == num */
	if (str)
	{
		new_head->str = _strdup(str);/** new head string */
		if (!new_head->str)
		{
			free(new_head);/** free new head */
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;/** head == new head */
	return (new_head);
}
/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 * Created by Chukwudike Igwe
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));/** new node ==malloc size of lists */

	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));/** memset new node */
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);/** addreess of pointer to node */
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;/** node to next */
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);/** the return of new node */
}
/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 * Created by partners in the project
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");/** printin only the str */
		_puts("\n");
		h = h->next;/** h==next */
		i++;
	}
	return (i);
}
/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 * created by Chukwudike Igwe
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;/** node == head */
		*head = (*head)->next;
		free(node->str);/** freeing node to str */
		free(node);
		return (1);
	}
	node = *head;/** node == head */
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);/** freeing node str */
			free(node);
			return (1);
		}
		i++;
		prev_node = node;/** prev node == node */
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 * Created by Chukwudike Igwe
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;/** head ptr */
	head = *head_ptr;
	node = head;/** node == head */
	while (node)
	{
		next_node = node->next;
		free(node->str);/** freeing node str */
		free(node);
		node = next_node;/** node == next node */
	}
	*head_ptr = NULL;
}
