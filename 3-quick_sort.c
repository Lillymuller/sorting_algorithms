#include "sort.h"

/**
 * lomuto_partition - partitions the given array
 * @array: array given to be sorted
 * @lower: start of the array
 * @upper: end of the array
 * @size: size of array
 * Return: returns the upper position
 */

int lomuto_partition(int *array, int lower, int upper, size_t size)
{
	int i = lower, j = upper;
	int tmp;
	int pivot = array[i];

	while (i < j)
	{
		while (array[i] <= pivot)
		{
			i++;
		}
		while (array[j] > pivot)
		{
			j--;
		}

		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[lower];
	array[lower] = array[j];
	array[j] = tmp;
	print_array(array, size);

	return (j);
}

/**
 * lomuto_sort - sorts an array of integers using quick sort algorithm
 * @array: array given to be sorted
 * @lower: start of array
 * @upper: end of array
 * @size: size of array
 * Return: void
 */

void lomuto_sort(int *array, int lower, int upper, size_t size)
{
	int lock;

	if (lower < upper)
	{
		lock = lomuto_partition(array, lower, upper, size);
		lomuto_sort(array, lower, lock - 1, size);
		lomuto_sort(array, lock + 1, upper, size);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort algorithm
 * @array: array given to be sorted
 * @size: size of array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, 0, size - 1, size);
}
