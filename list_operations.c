#include "header.h"

int is_sorted(t_stack *list)
{
	int nothing;

	while (list && list->next)
	{
		nothing = list->num;
		if (nothing > list->next->num)
			return (0);
		else
			list = list->next;
	}
	return (1);
}

int is_rev_sorted(t_stack *list)
{
	int nothing;

	while (list && list->next)
	{
		nothing = list->num;
		if (nothing < list->next->num)
			return (0);
		else
			list = list->next;
	}
	return (1);
}

int *list_to_arr(t_stack *list)
{
	int i;
	int c;
	int *tab;
	t_stack *list_cpy;
	
	i = 0;
	c = 0;
	list_cpy = list;
	while (list_cpy)
	{
		list_cpy = list_cpy->next;
		i++;
	}
	tab = (int *)malloc(sizeof(int) * i);
	i = 0;
	list_cpy = list;
	while (list_cpy)
	{
		tab[c] = list_cpy->num;
		list_cpy = list_cpy->next;
		c++;
		i++;
	}
	return (tab);
}