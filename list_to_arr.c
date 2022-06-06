#include "header.h"

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
	quick_sort(tab, 0, i - 1);
	
	return (tab);
}