#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell sort
 * algorithm with Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Void
 */

void shell_sort(int *array, size_t size)
{
	int interval, i, j;
	int tmp;

	interval = 1;
	while (interval <= (int)size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			tmp = array[i];

			for (j = i; j >= interval && array[j - interval] > tmp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = tmp;
		}

		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}

