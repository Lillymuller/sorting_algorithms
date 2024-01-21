#include "sort.h"

/**
*bubble_sort - It sorts the array in ascending order
*@array: array to be sorted
*@size: number of elements in the array
*Return: void
*/

void bubble_sort(int *array, size_t size)
{
	int i, j;
	int num_elem = size;
	int flag = 0;
	int tmp;

	if (array == NULL || num_elem < 2)
		return;
	/* loop for number of pass*/
	for (i = 0; i < num_elem - 1; i++)
	{
		flag = 0;
		/*loop for number of comparision*/
		for (j = 0; j < num_elem - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
