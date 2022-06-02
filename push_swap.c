#include "header.h"

t_stack	*stack_new(int num)
{
	t_stack	*tmp;
	
	tmp = malloc(sizeof(t_stack));
	tmp->num = num;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_append(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = stack_last(*lst);
	tmp->next = new;
}

t_stack	*stack_arr(char **ptr)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (ptr[i])
	{
		stack_append(&lst, stack_new(atoi(ptr[i])));
		i++;
	}
	stack_add_index(&lst);
	return (lst);
}

void stack_add_index(t_stack **list)
{
	t_stack *list_cpy;
	int *tab;
	int i;

	i = 0;
	list_cpy = *list;
	tab = list_to_arr(*list);

	while (list_cpy)
	{
		i = 0;
		while (tab[i])
		{
			if (tab[i] == (list_cpy)->num)
			{
				(list_cpy)->index = i;
				(list_cpy)->binary = decimal_to_binary(i);
			}
			i++;
		}
		list_cpy = (list_cpy)->next;
	}
	list_cpy = *list;
}