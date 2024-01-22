#include "sort.h"

/**
 * radix_count_sort - the radix and count sort algorithms
 * @array: array to be sorted
 * @size: size of the array
 * @buffer: the location storage of the array
 * @i: the index of the array
 * @top: significant digit to sort
 * Return: void
 */

void radix_count_sort(int *array, size_t size, int *buffer, int i, int top)
{
	int num_elem = size;
	int count[10] = {0};

	for (i = 0; i < num_elem; i++)
		++count[(array[i] / top) % 10];
	for (i = 0; i < 10; i++)
		count[i] = count[i] + count[i - 1];

	for (i = num_elem - 1; i >= 0; i--)
	{
		buffer[--count[(array[i] / top) % 10]] = array[i];
	}

	for (i = 0; i < num_elem; i++)
		array[i] = buffer[i];
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
	int i;
	int *buffer;
	int top;

	if (array == NULL || size < 2)
		return;

	for (highest = array[0]; i < num_elem; i++)
	{
		if (array[i] > highest)
			highest = array[i];
	}

	buffer = malloc(sizeof(int) * num_elem);
	if (buffer == NULL)
		return;

	for (top = 1; (highest / top) > 0; top *= 10)
	{
		radix_count_sort(array, size, buffer, i, top);
		print_array(array, size);
	}
	free(buffer);
}
