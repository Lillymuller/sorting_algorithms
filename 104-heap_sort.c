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
	int lt = (2 * i) + 1;
	int rt = (2 * i) + 2;

	while (lt < num_elem && array[lt] > array[highest])
		highest = lt;

	while (rt < num_elem && array[rt] > array[highest])
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
	int tmp;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[1];
		array[1] = array[i];
		array[i] = tmp;
		print_array(array, size);
		max_heapify(array, size, i);
	}
}
