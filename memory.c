#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Created by Chukwudike Igwe
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);/** frees a pointer */
		*ptr = NULL;
		return (1);/** 1 will be returned if freed */
	}
	return (0);
}
