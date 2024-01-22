#include "sort.h"

/**
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
 */

void bitonic_seq(int *array, size_t size, size_t sequence, char fl, int begin)
{
	int div = sequence / 2;
	int UP = 1;
	int DOWN = 0;
	char *string = (fl == 1) ? "UP" : "DOWN";

	if (sequence > 1) 
	{
		printf("Merging [%lu/%lu] (%s:\n)", sequence, size, string);
		print_array(array + begin, sequence);

		bitonic_seq(array, size, div, UP, begin);
		bitonic_seq(array, size, div, DOWN, begin + div);
		bitonic_merge(array, size, sequence, fl, begin);

		printf("Merging [%lu/%lu] (%s:\n)", sequence, size, string);
		print_array(array + begin, sequence);
	}
}

/**
 */

void bitonic_sort(int *array, size_t size)
{
	int UP = 1;

	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, size, UP, 0);
}
