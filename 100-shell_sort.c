#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 *              with the Knuth sequence.
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Perform the shell sort */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		/* Print the array after each interval reduction */
		print_array(array, size);
		gap /= 3;
	}
}
