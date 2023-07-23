#include "sort.h"

/**
 * insertion_sort_list - insertion sort for a doubly linked list
 * @list: doubly linked list
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *insrt, *pre, *tmp, *head;

	head = *list;
	if (list == NULL || head == NULL || head->next == NULL)
		return;
	curr = head->next;
	while (curr != NULL)
	{
		insrt = curr;
		pre = curr->prev;

		while (pre != NULL && pre->n > insrt->n)
		{
			pre->next = insrt->next;
			if (insrt->next != NULL)
				insrt->next->prev = pre;
			insrt->prev = pre->prev;
			insrt->next = pre;
			if (pre->prev != NULL)
				pre->prev->next = insrt;
			else
				head = insrt;
			insrt->prev = pre->prev;
			pre->prev = insrt;
			pre = insrt->prev;
			tmp = head;
			while (tmp != NULL)
			{
				printf("%d", tmp->n);
				if (tmp->next != NULL)
					printf(", ");
				tmp = tmp->next;
			}
			printf("\n");
		}
		curr = curr->next;
	}
	*list = head;
}
