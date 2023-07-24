#include "sort.h"

/**
 * length_list - return the lenght of list
 * @size: List that measure
 *
 * Return: return count
 */
int length_list(listint_t *size)
{
	int count = 0;

	while (size)
	{
		count++;
		size = size->next;
	}
	return (count);
}

/**
 * insertion_sort_list - function that sort the list
 * @list: list that sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	listint_t *one = NULL;
	listint_t *two = NULL;
	listint_t *three = NULL;
	listint_t *four = NULL;

	if (!list || !(*list) || length_list(*list) < 2)
		return;
	current = *list;
	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;
			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
			       *list = three;
			two->prev = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
