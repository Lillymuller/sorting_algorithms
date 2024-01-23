#include "sort.h"

/**
*merge_array - It sortes the subarrays
*@array: main array to be sorted
*@arri: secound array to hold the sorrted array
*@low: index for the lower bound
*@middle : index for middle element
*@up: index for upper bound
*
*/

void merge_array(int *array, int *arri, size_t low, size_t middle, size_t up)
{
	size_t a = low;
	size_t b = middle + 1;
	size_t last = low;

	printf("Merging...\n[left]: ");
	print_array(array + low, middle - low);

	printf("[right]: ");
	print_array(array + middle, up - middle);

	/* First while loop: */
	while (a < middle && b < up)
	{
		arri[last++] = (array[a] < array[b]) ? array[a++] : array[b++];
	}

	/*Second while loop:*/
	while (a < middle)
	{
		arri[last++] = array[a++];
	}

	/* Third while loop: */
	while (b < up)
	{
		arri[last++] = array[b++];
	}

	/* Fourth while loop: */
	a = low;
	while (a < up)
	{
		array[a++] = arri[last++];
	}

	printf("[Done]: ");
	print_array(array + low, up - low);
}



/*
*merge_recursive - excuit the merge sorting algorithum
*@array: array to be sorted
*@arri: array that holds sorted array
*@low: index for the lower bound
*@up: index for the upper bound
*Return: void
*/

void merge_recursive(int *array, int *arri, size_t low, size_t up)
{
	size_t middle;

	if (up - low > 1)
	{
		middle = low + (up - low) / 2;

		merge_recursive(array, arri, low, middle);
		merge_recursive(array, arri, middle + 1, up);
		merge_array(array, arri, low, middle, up);
	}
}



/**
*merge_sort - sorts an array of integers in ascending order
*@array: array to be sorted
*@size: size of the array given
*
*/

void merge_sort(int *array, size_t size)
{
	int *arri;

	if (array == NULL || size < 2)
		return;

	arri = malloc(sizeof(int) * size);

		if (arri == NULL)
			return;

	 merge_recursive(array, arri, 0, size);

	 free(arri);
}
