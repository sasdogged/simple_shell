#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 * Created by Chukwudike Igwe
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);/** the absolute source */
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;/** the destination poiter */
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 * created by Chukwudike Igwe
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);/** return NULL if not duplicated */
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;/** the string to be duplicated */
	return (ret);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Packaged by Chukwudike Igwe
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;/** remember integer is zero */
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Created by Chukwudike Igwe
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);/** error will be -1 if errno is in order */
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;/** the character c will be written to stdout */
	return (1);
}
