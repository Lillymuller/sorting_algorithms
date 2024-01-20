#include "sort.h"

/**
*shell_sort - sorts an array of integers in ascending order
*@array: array to be sorted
*@size: size of array
*
*/

void shell_sort(int *array, size_t size)
{
	size_t gap, low, up;
	size_t num_elem = size;
	int tmp;

	if (array == NULL || size < 2)
		return;

	/* loop for gap */
	for (gap = num_elem / 3; gap >= 1; gap /= 3)
	{
		gap = (gap * 3) + 1;
		/* loop move from up to down wards */
		for (up = gap; up < num_elem; up++)
		{
			/* loop that move from lower to upper */
			for (low = up - gap; low >= 0; low -= gap)
			{
				if (array[low + gap] < array[low])
				{
					break;
				}

					tmp = array[low + gap];
					array[low + gap] = array[low];
					array[low] = tmp;
					print_array(array, size);
			}
		}
	}
}
