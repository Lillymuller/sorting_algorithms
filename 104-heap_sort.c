#include "sort.h"

/**
 * max_heapify - builds the maximum heap
 * @array: array to be sorted
 * @size: size of the array
 * @i: the max of the heap
 * Return: void
 */

void max_heapify(int *array, size_t size, int i)
{
	int num_elem = size;
	int tmp;
	int highest = i;
	int lt = 2 * i;
	int rt = (2 * i) + 1;

	while (lt <= num_elem && array[lt] > array[highest])
		highest = lt;

	while (rt <= num_elem && array[rt] > array[highest])
		highest = rt;

	if (highest != i)
	{
		tmp = array[i];
		array[i] = array[highest];
		array[highest] = tmp;
		print_array(array, size);
		max_heapify(array, size, highest);
	}
}

/**
 * heap_sort -  sorts an array of integers using heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int num_elem = size;
	int tmp;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = num_elem / 2; i >= 1; i--)
		max_heapify(array, size, i);

	for (i = num_elem; i > 1; i--)
	{
		tmp = array[i];
		array[i] = array[i];
		array[i] = tmp;
		print_array(array, size);
		max_heapify(array, size, i);
	}
}
