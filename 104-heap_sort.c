#include "sort.h"

/**
 * max_heapify - builds the maximum heap
 * @array: array to be sorted
 * @size: size of the array
 * @i: the max of the heap
 * @low: the bottom of the heap
 * Return: void
 */

void max_heapify(int *array, size_t size, int i, int low)
{
	int bottom = low;
	int tmp;
	int highest = i;
	int lt = (2 * i) + 1;
	int rt = (2 * i) + 2;

	while (lt < bottom && array[lt] > array[highest])
		highest = lt;

	while (rt < bottom && array[rt] > array[highest])
		highest = rt;

	if (highest != i)
	{
		tmp = array[i];
		array[i] = array[highest];
		array[highest] = tmp;
		print_array(array, size);
		max_heapify(array, size, i, low);
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
	int num_elem = size;
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (num_elem / 2) - 1; i >= 1; i--)
		max_heapify(array, size, num_elem, i);

	for (i = num_elem - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
