#include "header.h"

int ft_avg_cmp(t_stack *lista, int avg)
{
	t_stack *list;
	int flag;

	flag = 0;
	list = lista;
	while (list)
	{
		if (avg < list->num)
			flag = 1;
		list = list->next;
	}
	if (flag == 1)
		return (1);
	return (0);
}

int ft_cmp(int num1, int num2)
{
	if (num1 <= num2)
		return (1);
	return (0);
}

void push_coma(t_stack **lista, t_stack **listb)
{
	int avg;
	t_stack *tmp;

	tmp = *lista;
	avg = tab_avg(*lista);
	while (tmp)
	{
		if (ft_avg_cmp(*lista, avg) == 0)
			break;
		if (ft_cmp((*lista)->num, avg) == 0)
		{
			handler("pb", lista, listb);
			tmp = *lista;
		}
		else
		{
			handler("ra", lista, listb);
			tmp = *lista;
		}
		tmp = tmp->next;
	}
}

void coma(t_stack **lista)
{
	int i;
	int j;
	int sign;
	int count;
	int *tab;
	t_stack *lista_cpy;

	i = 0;
	count = 0;
	sign = 0;
	lista_cpy = *lista;

	tab = list_to_arr(*lista);
	while (lista_cpy)
	{
		j = 0;
		while (tab[j])
		{
			if (lista_cpy->num == tab[j])
			{
				sign = j - i;
				if (sign > 0)
					handler("ra", lista, NULL);
				if (sign < 0)
					handler("rra", lista, NULL);
				if (sign == 0)
					handler("sa", lista, NULL);
				count++;
			}
			j++;
		}
		lista_cpy = lista_cpy->next;
		i++;
	}
}

int compaire(t_stack **lista, t_stack **listb)
{
	// lista = coma(lista, listb);
	push_coma(lista, listb);
	coma(lista);
	ft_lstprint(*lista, "a");
	ft_lstprint(*listb, "b");
	t_stack	*list;

	list = *listb;
	while (list)
	{
		handler("pa", lista, listb);
		list = list->next;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_stack *lista;
	t_stack *listb;

	(void)ac;
	lista = stack_arr(&av[1]);
	listb = NULL;

	// ft_lstprint(lista, "a");
	// ft_lstprint(listb, "b");
	compaire(&lista, &listb);
}