#include "sort.h"

/**
 * bitonic_merge - merges the bitonic list
 * @array: array to be sorted
 * @size: size of the array
 * @sequence: sequence of the bitonic list
 * @fl: flow of the bitonic list
 * @begin: start of the bitonic list
 * Return: void
 */

void bitonic_merge(int *array, size_t size, int sequence, char fl, int begin)
{
	int i;
	int tmp;
	int jp = sequence / 2;
	int UP = 1;
	int DOWN = 0;

	if (sequence > 1)
	{
		i = begin;
		while (i < begin + jp)
		{
			if ((fl == UP && array[i] > array[i + jp]) ||
			(fl == DOWN && array[i] < array[i + jp]))
			{
				tmp = array[i];
				array[i] = array[i + jp];
				array[i + jp] = tmp;
			}
			i++;
		}
		bitonic_merge(array, size, jp, fl, begin);
		bitonic_merge(array, size, jp, fl, begin + jp);
	}
}

/**
 * bitonic_sequence - sequence of the bitonic list
 * @array: array to be sorted
 * @size: size of the array
 * @sequence: sequence list
 * @fl: flow of the bitonic list
 * @begin: start of the bitonic list
 * Return: void
 */

void bitonic_sequence(int *array, size_t size, size_t sequence, char fl,
	int begin)
{
	int div = sequence / 2;
	int UP = 1;
	int DOWN = 0;
	char *string = (fl == 1) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s:\n)", sequence, size, string);
		print_array(array + begin, sequence);

		bitonic_sequence(array, size, div, UP, begin);
		bitonic_sequence(array, size, div, DOWN, begin + div);
		bitonic_merge(array, size, sequence, fl, begin);

		printf("Merging [%lu/%lu] (%s:\n)", sequence, size, string);
		print_array(array + begin, sequence);
	}
}

/**
 * bitonic_sort - sorts an array of integers of bitonic sort
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{
	int UP = 1;

	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, size, UP, 0);
}
