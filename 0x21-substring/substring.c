#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "substring.h"


int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i;
	char *result;
	int offset = 0;


	for (i = nb_words; i > 0; i--)
	{
		offset += strlen(words[i - 1]);
		printf("%s\n", s + offset);
		result = strstr(s + offset, words[i - 1]);
		printf("%s\n", result + offset);
		if (result)
		{
			printf("%li\n", result - s);
			
		}
	}
	return n;
}