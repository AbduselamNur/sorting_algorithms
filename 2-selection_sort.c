#include "sort.h"

/**
 * selection_sort - Sorts ana array of integers in ascending with selection
 * @array: given array
 * @size: number of elements in the array
 *
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
