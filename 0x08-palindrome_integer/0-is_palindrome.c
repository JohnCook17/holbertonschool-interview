#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindrome.h"


/**
 * itoa - takes an int and changes it to a str
 * @val: the value to change to str
 * @base: the number base
 * Return: the buffer
 */
char *itoa(int val, int base)
{
	static char buf[32] = {0};

	int i = 30;

	for (; val && i; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];

	return (&buf[i + 1]);
}


/**
 * is_palindrome - determines if a number is a palindrome
 * @n: the number to check
 * Return: 0 if not 1 if so
 */
int is_palindrome(unsigned long n)
{
	char *n_str;
	int length_n;
	int start_n = 0;

	n_str = itoa(n, 10);
	length_n = strlen(n_str);

	if (length_n == 1)
		return (1);
	while (start_n != length_n)
	{
		if (n_str[start_n] != n_str[length_n - 1])
		{
			return (0);
		}
		start_n++;
		length_n--;
	}
	return (1);
}
