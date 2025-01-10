#include "sort.h"

/**
 * selection_sort - Sorts array of integers in ascending order using Selection Sort
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Description: Prints the array each time two elements are swapped.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
