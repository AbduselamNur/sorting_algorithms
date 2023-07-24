#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending
 * with selection algorithm
 * @array: given array
 * @size: number of elements in the array
 *
 * Return: Void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, minIndex;
	int tmp;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
		{
			tmp = array[i];
			array[i] = array[minIndex];
			array[minIndex] = tmp;
			print_array(array, size);
		}
	}
}
