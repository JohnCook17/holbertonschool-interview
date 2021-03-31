#include "holberton.h"

/**
 * my_stcmp - compares two strings were the second may contain a wild card
 * @s1: the first string has no wild cards
 * @s2: the second string might have wild cards
 * @i: keeps track of where in the string
 * Return: 0 on no match 1 on match
 */
int my_stcmp(char *s1, char *s2, int i)
{
	unsigned char c1 = *s1, c2 = *s2;


	if ((c1 == c2 || c2 == '*') && (c1 != '\0'))
	{
		if (*s2 == '*' && s2[i] && s2[i] != c1)
		{
			i++;
			return (my_stcmp(s1 + 1, s2, i));
		}
		return (my_stcmp(s1 + 1, s2 + 1, i));
	}
	if (c1 == '\0' && c2 != '\0')
	{
		return (0);
	}

	return (1);
}
/**
 * wildcmp - entry point
 * @s1: string 1
 * @s2: string 2
 * Return: 0 on no match 1 on match
 */
int wildcmp(char *s1, char *s2)
{
	return (my_stcmp(s1, s2, 0));
}
