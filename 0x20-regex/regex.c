#include "regex.h"

/**
 * regex_match - matches a string with the pattern, * = multiple char, . = 1
 * @str: the string to match
 * @pattern: the pattern to match
 * Return: 0 on no match 1 on match
 */
int regex_match(char const *str, char const *pattern)
{
	int i = 0;
	int j = 0;

	while (str[i] != '\0')
	{
		if (str[i] == pattern[i])
		{
			i++;
			j = i;
		}
		else if (pattern[i] == '.')
		{
			i++;
			j = i;
		}
		else if (str[i] == pattern[j])
		{
			j++;
			i++;
		}
		else if (pattern[j] == '*')
				i++;
		else
			return (0);
	}
	return (1);
}
