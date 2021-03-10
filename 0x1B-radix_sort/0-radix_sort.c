#include <stdlib.h>
#include "sort.h"
/**
 * get_max - sets max to array position 0, goes through and finds the new max
 * @a: the array
 * @size: the size of array
 * Return: the max value in the array
 */
int get_max(int a[], size_t size)
{
	int max = a[0];
	size_t i;

	for (i = 0; i < size; i++)
		if (a[i] > max)
			max = a[i];

	return (max);
}
/**
 * radix_sort - sorts by least significant digit and puts into buckets of the
 * same signifigance.
 * @array: the array to sort
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int bucket[10][10], bucket_count[10];
	int j;
	size_t i, k, r, NOP = 0, divisor = 1, lar, pass;

	lar = get_max(array, size);
	while (lar > 0)
	{
		NOP++;
		lar /= 10;
	}
	for (pass = 0; pass < NOP; pass++)
	{
		for (i = 0; i < size; i++)
		{
			bucket_count[i] = 0;
		}
		for (i = 0; i < size; i++)
		{
			r = (array[i] / divisor) % 10;
			bucket[r][bucket_count[r]] = array[i];
			bucket_count[r] += 1;
		}
		i = 0;
		for (k = 0; k < 10; k++)
		{
			for (j = 0; j < bucket_count[k]; j++)
			{
				array[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 10;
		print_array(array, size);
	}
}
