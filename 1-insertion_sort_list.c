#include "sort.h"
/**
*insertion_sort_list - function that sorts a double linked list.
*@list: list input
*Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *top;
	listint_t *next_node, *tmp;
	int flag = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	top = (*list)->next;

	while (top != NULL)
	{
		tmp = top;
		while (tmp->prev != NULL)
		{
			flag = 0;
			if (tmp->n < tmp->prev->n)
			{
				if (tmp->prev->prev != NULL)
					 /*start swapping*/
					tmp->prev->prev->next = tmp;
				tmp->prev->next = tmp->next;
				next_node = tmp->prev->prev;
				tmp->prev->prev = tmp;

				if (tmp->next != NULL)
					/*start swapping nodes*/
					tmp->next->prev = tmp->prev;
				tmp->next = tmp->prev;
				tmp->prev = next_node;
				flag = 1;
				if (tmp->prev == NULL)
					*list = tmp;
				print_list(*list);
			}
			if (flag == 0)
				tmp = tmp->prev;
		}
		top = top->next;
	}
}







/**
*insertion_sort_list - function that sorts a double linked list.
*@list: list input
*Return: void
*
*
*void insertion_sort_list(listint_t **list)
*{
* int i, j;
*int num_elem;
*int tmp, array;
*
*for (i = 1; i < num_elem; i++)
*{
*tmp = array[i];
*j = i - 1;
*
*while (j >= num_elem && array[j] > tmp)
*{
*array[j + 1] = array[j];
*j--;
*}
*array[j + 1] = tmp;
*print_list(*list);
*}
*}
*/
