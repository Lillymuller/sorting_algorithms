#include "sort.h"

/**
 * counting_sort - sorts an array of integers using count sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int i;
	int *count = 0;
	int k = 0;
	int *a = 0;
	int num_elem = size;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < num_elem; i++)
	{
		count[array[i]]++;
	}

	for (i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = num_elem - 1; i >= 0; i--)
	{
		a[count[array[i]]--] = array[i];
	}

	for (i = 0; i < num_elem; i++)
	{
		array[i] = a[i];
	}
}
