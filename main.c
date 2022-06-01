#include "header.h"

int ft_cmp(int num1, int num2)
{
	if (num1 <= num2)
		return (1);
	return (0);
}

t_stack *push_coma(t_stack *lista, t_stack *listb)
{
	int avg;
	t_stack *tmp;

	tmp = lista;
	avg = tab_avg(lista);
	while (tmp != 0)
	{
		if (ft_cmp(tmp->num, avg) == 1)
		{
			handler("pb", &lista, &listb);
			tmp = lista;
		}
		tmp = tmp->next;
	}
	ft_lstprint(lista, "a");
	ft_lstprint(listb, "b");
	return (lista);
}

t_stack *coma(t_stack *lista, t_stack *listb)
{
	(void)listb;
	int i;
	int j;
	int sign;
	int count;
	int *tab;
	t_stack *lista_cpy;

	i = 0;
	count = 0;
	sign = 0;
	lista_cpy = lista;
	while (lista_cpy)
	{
		j = 0;
		while (tab[j])
		{
			if (lista_cpy->num == tab[j])
			{
				sign = j - i;
				if (sign > 0)
					handler("ra", &lista, &listb);
				if (sign < 0)
					handler("rra", &lista, &listb);
				if (sign == 0)
					handler("sa", &lista, &listb);
				i = 0;
				lista_cpy = lista;
				tab = list_to_arr(lista);
				count++;
			}
			j++;
		}
		lista_cpy = lista_cpy->next;
		i++;
	}
	// ft_lstprint(lista, "a");
	// ft_lstprint(listb, "b");
	return (lista);
}

int compaire(t_stack *lista, t_stack *listb)
{
	// lista = coma(lista, listb);
	lista = push_coma(lista, listb);
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
	compaire(lista, listb);
}