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
    size_t i, j, k, minIndex;
    int tmp;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j;
            }
        }

	if (minIndex != i)
        {
            tmp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = tmp;

            for (k = 0; k < size; k++)
            {
                if (k == size - 1)
                    printf("%d", array[k]);
                else
                    printf("%d, ", array[k]);
            }
            printf("\n");
        }
    }
}
