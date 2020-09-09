#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - prints the array
 * @array: the array to print
 * @left: the left index of array
 * @right: the right index of array
 */

void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		if (left == right - 1)
			printf("%i\n", array[left]);
		else
			printf("%i, ", array[left]);
		left++;
	}
}
/**
 * helper - a helper function to search the array
 * @array: the array to search
 * @left: the left index of array
 * @right: the right index of array
 * @value: the value to search for
 * Return: the index where value is found
 */
int helper(int *array, size_t left, size_t right, int value)
{
	size_t mid = (left + (right - left) / 2);

	if (array[right] < value)
		return (-1);
	if (array[mid] == value)
	{
		print_array(array, left, right);
		return (mid);
	}
	if (array[mid] > value)
	{
		print_array(array, left, right);
		return (helper(array, left, mid - 1, value));
	}
	if (array[mid] < value)
	{
		print_array(array, left, right);
		return (helper(array, mid + 1, right, value));
	}
	return (-1);
}
/**
 * advanced_binary - returns the index of the value found
 * @array: the array to search in
 * @size: the size of the array
 * @value: the value to search for
 * Return: the index of the value
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t l = 0;
	size_t r = size;

	return (helper(array, l, r, value));
}
