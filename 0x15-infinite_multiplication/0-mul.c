#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "holberton.h"
/**
 * memory_set - sets memory of dest to val
 * @dest: the destination
 * @val: the value
 * @len: the length
 * Return: pointer to dest
 */
void *memory_set(void *dest, int val, size_t len)
{
	unsigned char *ptr = dest;

	while (len-- > 0)
		*ptr++ = val;

	return (dest);
}
/**
 * memory_move - moves a block of memory
 * @dest: the destination
 * @src: the source
 * @len: the length
 * Return: a pointer to dest
 */
void *memory_move(void *dest, void *src, size_t len)
{
	char *d = dest;
	char *s = src;

	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		char *lasts = s + (len - 1);
		char *lastd = d + (len - 1);

		while (len--)
			*lastd-- = *lasts--;
	}
	return (dest);
}
/**
 * string_compair - compairs two strings
 * @a: string a
 * @b: string b
 * Return: 0 on match 1 on not match
 */
int string_compair(char *a, char *b)
{
	if (a == b)
		return (0);
	else
		return (1);
}
/**
 * string_len - finds the len of a string
 * @a: the string to find the len of
 * Return: the len of string
 */
int string_len(char *a)
{
	int i = 0;

	while (a[i])
	{
		i++;
	}
	return (i);
}
/**
 * c_to_i - char to int
 * @a: the char to change to int
 * @c: the whole sequence, for free if fail
 * Return: int
 */
int c_to_i(char a, char *c)
{
	if (a == '0')
		return (0);
	else if (a == '1')
		return (1);
	else if (a == '2')
		return (2);
	else if (a == '3')
		return (3);
	else if (a == '4')
		return (4);
	else if (a == '5')
		return (5);
	else if (a == '6')
		return (6);
	else if (a == '7')
		return (7);
	else if (a == '8')
		return (8);
	else if (a == '9')
		return (9);
	free(c);
	exit(98);
}
/**
 * print_error - prints the word Error
 */
void print_error(void)
{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
}
/**
 * print_char - prints the char
 * @c: the char * to print
 */
void print_char(char *c)
{
	int i, j;

	i = string_len(c);
	j = 0;
	while (i != j)
	{
		_putchar(c[j]);
		j++;
	}
	_putchar('\n');
	free(c);
}
/**
 * main - infinite multiplication
 * @argc: the number of args
 * @argv: the values of args
 * Return: no value
 */
int main(int argc, char **argv)
{
	int i = 0, j = 0, k = 0, n, carry, la, lb;
	char *a, *b, *c;

	if (argc != 3)
	{
		print_error();
		exit(98);
	}
	a = argv[1];
	b = argv[2];
	c = malloc(sizeof(char));
	if (c == NULL)
	{
		free(c);
		print_error();
		exit(98);
	}
	if (!string_compair(a, "0") || !string_compair(b, "0"))
	{
		c[0] = '0', c[1] = '\0';
		print_error();
		exit(98);
	}
	la = string_len(a);
	lb = string_len(b);
	memory_set(c, '0', la + lb);
	c[la + lb] = '\0';
	for (i = la - 1; i >= 0; i--)
	{
		for (j = lb - 1, k = i + j + 1, carry = 0; j >= 0; j--, k--)
		{
			n = c_to_i(a[i], c) * c_to_i(b[j], c) + c_to_i(c[k], c) + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
		}
		c[k] += carry;
	}
	if (c[0] == '0')
		memory_move(c, c + 1, la + lb);
	print_char(c);
	return(1);
}
