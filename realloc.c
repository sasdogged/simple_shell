#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * created by Chukwudike Igwe
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;/** pointer to the memory */
	return (s);
}
/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);/** The frees of strings */
	free(a);
}
/**
 * _realloc - reallocates a block of memo
 * @ptr: pointer to prev malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Created by Chukwudike Igwe
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));/** the return of Malloc, New size */
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);/** pointer to da ol'block nameen */

	p = malloc(new_size);
	if (!p)
		return (NULL);/** return to NULL upon completion */

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr); /** the frees of pointers */
	return (p);
}
