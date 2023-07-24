#include "sort.h"

/**
 * quick_sort - sorts an array ascending by quick sort
 * @array: array that sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	recursion(array, 0, (int)size - 1, size);
}

/**
 * recursion - recursion function
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = parti(array, left, right, size);
		recursion(array, left, piv - 1, size);
		recursion(array, piv + 1, right, size);
	}
}

/**
 * parti - gives index for Quicksort
 * @array: array find in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of array
 *
 * Return: the index piv element
 */
int parti(int *array, int left, int right, size_t size)
{
	int tmp, i;
	int j;

	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < array[right])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
