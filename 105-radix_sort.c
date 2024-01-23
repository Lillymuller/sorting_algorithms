#include "sort.h"

/**
 * radix_count_sort - the radix and count sort algorithms
 * @array: array to be sorted
 * @size: size of the array
 * @buffer: the location storage of the array
 * @top: significant digit to sort
 * Return: void
 */

void radix_count_sort(int *array, size_t size, int *buffer, int top)
{
	size_t num_elem = size;
	size_t j;
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (j = 0; j < num_elem; j++)
	{
		++count[(array[j] / top) % 10];
	}
	for (j = 0; j < 10; j++)
	{
		count[j] = count[j] + count[j - 1];
	}
	for (j = num_elem - 1; (int)j >= 0; j--)
	{
		buffer[count[(array[j] / top) % 10] - 1] = array[j];
		--count[(array[j] / top) % 10];
	}
	for (j = 0; j < num_elem; j++)
	{
		array[j] = buffer[j];
	}
}

/**
 * radix_sort - sorts an array of integers using radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int highest;
	int num_elem = size;
	int j;
	int *buffer;
	int top;

	if (array == NULL || size < 2)
		return;

	for (highest = array[0]; j < num_elem; j++)
	{
		if (array[j] > highest)
			highest = array[j];
	}

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	for (top = 1; (highest / top) > 0; top *= 10)
	{
		radix_count_sort(array, size, buffer, top);
		print_array(array, size);
	}
	free(buffer);
}
