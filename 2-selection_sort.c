#include "sort.h"

/**
 * selection_sort - sorts an array of integers using selection  algorithm
 * @array: list of elements to be sorted
 * @size: number of elements in the array
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	int a, b;
	int minimum;
	int num_elem = size;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < num_elem - 1; a++)
	{
		minimum = a;
		for (b = a + 1; b < num_elem; b++)
		{
			if (array[b] < array[minimum])
				minimum = b;
		}

		if (minimum != a)
		{
			tmp = array[a];
			array[a] = array[minimum];
			array[minimum] = tmp;
			print_array(array, size);
		}
	}
}
