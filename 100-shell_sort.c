#include "sort.h"

/**
*shell_sort - sorts an array of integers in ascending order
*@array: array to be sorted
*@size: size of array
*
*/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, low, up;
	size_t num_elem = size;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* loop for gap */
	for (; gap < num_elem / 3; gap = (gap * 3) + 1)
	{
		/* loop move from up to down wards */
		for (; gap > 0; gap /= 3)
		{
			/* loop that move from lower to upper */
			for (low = gap; low < num_elem; low++)
			{
				tmp = array[low];
				for (up = low; up >= gap && array[up - gap] > tmp; up -= gap)
				{
					array[up] = array[up - gap];
				}
				array[up] = tmp;
			}
			print_array(array, size);
		}
	}
}


