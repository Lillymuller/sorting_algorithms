#include "sort.h"

/**
*swap_cocktail - is a function for swapping
*@list: a double linked list to be sorted
*@tmp: given index for the given list
*@top: secound index
*
*/

void swap_cocktail(listint_t **list, listint_t *tmp, listint_t *top)
{

	if (top->prev == NULL)
	{
	top->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = top;
	tmp->next = top;
	top->prev = tmp;

	if (tmp->prev == NULL)
		*list = tmp;
	}

	else
	{
		tmp->prev->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = tmp->prev;
		top->prev->next = tmp;
		tmp->prev = top->prev;
		top->prev = tmp;
		tmp->next = top;
	}
}






/**
 * cocktail_sort_list - sorts a doubly linked list of integers using cocktail
 * @list: list of the sorted algorithm
 * Return: void
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *top;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tmp = (*list);

	while (flag != 0)
	{
		flag = 0;
		while (tmp->next != NULL)
		{
			top = tmp->next;

			if (top && tmp->n > top->n)
		{
			swap_cocktail(list, top, tmp);
			print_list(*list);
			flag = 1;
		}
			tmp = tmp->next;
		}
		tmp = tmp->prev;

		while (tmp->prev != NULL)
		{
			top = tmp->prev;

			if (top && tmp->n < top->n)
		{
			swap_cocktail(list, tmp, top);
			print_list(*list);
			flag = 1;
		}
			tmp = tmp->prev;
		}

		tmp = tmp->next;
	}
}
