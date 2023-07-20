#include "sort.h"

/**
 * bubble_sort - Sort array of strings
 * @array: array of integers
 * @size: size of array
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;
	int tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				for (k = 0; k < size; k++)
				{
					if (k == size - 1)
					{
						printf("%d", array[k]);
					}
					else
					{
						printf("%d, ", array[k]);
					}
				}
				printf("\n");
			}
		}
	}
}

