#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: First node to swap
 * @node2: Second node to swap
 *
 * Return: Void
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Cocktail shaker sort for a doubly linked list
 * @list: Pointer to the head of the list
 *
 * Return: Void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right, *tmp;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	left = *list;
	right = tmp = NULL;

	do
	{
		swapped = 0;
		while (left && left->next != right)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				print_list(*list);
				swapped = 1;
			}
			else
				left = left->next;
		}
		right = left;

		if (!swapped)
			break;

		swapped = 0;
		while (right && right->prev != tmp)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				print_list(*list);
				swapped = 1;
			}
			else
				right = right->prev;
		}
		tmp = right;
	} while (swapped);
}
