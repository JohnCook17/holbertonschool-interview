#include <stdio.h>
#include "sort.h"
/**
 * iParent - determines the parent of i
 * @i: the index to determine parent of
 * Return: the parent
 */
size_t iParent(size_t i)
{
	return ((i - 1) / 2);
}
/**
 * iLeftChild - determines the left child
 * @root: the root to dertermine child of
 * Return: the left child
 */
size_t iLeftChild(size_t root)
{
	return (2 * root + 1);
}
/**
 * sift_down - sifts down
 * @array: the array to change
 * @size: the size of the array
 * @end: the end
 */
void sift_down(int *array, size_t size, size_t end)
{
	size_t root = size;
	size_t child;
	size_t swap;
	int temp;

	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
		}
		else
			break;
	}

}
/**
 * heapify - makes a heap
 * @array: the array to heap
 * @count: the size - 1 for 0 index
 */
void heapify(int *array, size_t count)
{
	size_t start = iParent(count - 1);

	while (start != 0)
	{
		sift_down(array, start, count - 1);
		print_array(array, count);
		start--;
	}
}
/**
 * heap_sort - the sorting driver
 * @array: the array to sort
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;
	int temp;

	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		end--;
		sift_down(array, 0, end);
		print_array(array, size);
	}
}
