#include "sort.h"
/**
 *  selection_sort -  a function that sorts an array of integers
 *  in ascending order using the Selection sort algorithm
 *  @array: The array that sort
 *  @size: the size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t min;

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
			int new = array[i];

			array[i] = array[min];
			array[min] = new;
			print_array(array, size);
		}
	}
}
