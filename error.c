#include "shell.h"

/**
 * eputchar - it writes the character to stderr
 * @c: The character to print in the screen
 *
 * Return: On success 1.
 * On fail, -1 is returned, and errno is set.
 */
int eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * eputs - prints an input char
 * @str: the char to be printed
 *
 * Return: Nothing
 */
void eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		eputchar(str[i]);
		i++;
	}
}


/**
 * putfiled - writes the character to given string
 * @c: The character to print in the screen
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putfiled(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * putsfiled - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int putsfiled(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += putfiled(*str++, fd);
	}
	return (i);
}
