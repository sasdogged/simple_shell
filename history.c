#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 * Created by Chukwudike Igwe
 * Return: allocated string containg history file
 */

char *get_history_file(ino_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");/** info home, dir */
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);/** if not contain history file, return NULL */
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);/** buf strcat */
	return (buf);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 * Created by Chukwudike and partner
 * Return: 1 on success, else -1
 */
int write_history(ino_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);/** get history file  name */
	list_t *node = NULL;

	if (!filename)
		return (-1);/** if not successful return negative 1 */

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);/** open file name */
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);/** new line of putfd */
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);/** really closed */
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 * Fixed by Chukwudike Igwe
 * Return: histcount on success, 0 otherwise
 */
int read_history(ino_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;/** file size */
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);/** getting file */

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);/** read only file name */
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;/** the file size */
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));/** malloc, size of xter */
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;/** read file size */
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;/** buf file size */
			build_history_list(info, buf + last, linecount++);
			last = i + 1;/** build history list */
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);/** counting line */
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);/** delete node at index */
	renumber_history(info);
	return (info->histcount);/** history counting */
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 * Created by Chukwudike Igwe
 * Return: Always 0
 */
int build_history_list(ino_t *info, char *buf, int linecount)
{
	list_t *node = NULL;/** NULL node */

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);/** add node end */

	if (!info->history)
		info->history = node;/** info history node */
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 * Created by Chukwudike Igwe
 * Return: the new histcount
 */
int renumber_history(ino_t *info)
{
	list_t *node = info->history;/** info history node */
	int i = 0;

	while (node)
	{
		node->num = i++;/** num node */
		node = node->next;
	}
	return (info->histcount = i);/** info histcount */
}
