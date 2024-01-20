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
	int *count;
	int k;
	int *a;
	int num_elem = size;

	if (array == NULL || size < 2)
		return;
	for (k = array[0]; i < num_elem; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	a = malloc(sizeof(int) * num_elem);
	if (a == NULL)
		return;
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(a);
		return;
	}
	for (i = 0; i < num_elem; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; i < (k + 1); i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	for (i = num_elem - 1; i >= 0; i--)
	{
		a[--count[array[i]]] = array[i];
	}
	for (i = 0; i < num_elem; i++)
	{
		array[i] = a[i];
	}
	free(a);
	free(count);
}
