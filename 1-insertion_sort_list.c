#include "sort.h"

/**
 * swap_nodes - It is to swap two nodes in a listint_t doubly-linked list.
 * @hd: It is a pointer to the head of the doubly-linked list.
 * @nd1: It is a pointer to the first node to swap.
 * @nd2: it is the second node to swap.
 */
void swap_nodes(listint_t **hd, listint_t **nd1, listint_t *nd2)
{
	(*nd1)->next = nd2->next;
	if (nd2->next != NULL)
		nd2->next->prev = *nd1;
	nd2->prev = (*nd1)->prev;
	nd2->next = *nd1;
	if ((*nd1)->prev != NULL)
		(*nd1)->prev->next = nd2;
	else
		*hd = nd2;
	(*nd1)->prev = nd2;
	*nd1 = nd2->prev;
}

/**
 * insertion_sort_list - This is to sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: It is a pointer to the head of a doubly-linked list of integers.
 *
 * Description: This prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
