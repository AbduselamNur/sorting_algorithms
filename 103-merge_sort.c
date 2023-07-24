#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted array
 * @array: The original array containing the two subarrays
 * @left: Pointer to the left subarray
 * @left_size: Size of the left subarray
 * @right: Pointer to the right subarray
 * @right_size: Size of the right subarray
 *
 * Return: Void
 */

void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	size_t i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort_recursive - Recursive function to sort an array using merge sort
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Void
 */

void merge_sort_recursive(int *array, size_t size)
{
	if (size < 2)
	return;

	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;
	size_t left_size = mid;
	size_t right_size = size - mid;

	merge_sort_recursive(left, left_size);
	merge_sort_recursive(right, right_size);
	merge(array, left, left_size, right, right_size);
}

/**
 * merge_sort - Top-down merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 *
 * Return: Void
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}

