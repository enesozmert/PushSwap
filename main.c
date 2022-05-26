#include "header.h"

int coma(t_stack *lista, t_stack *listb, int *tab)
{
	int i;
	int j;
	int count;
	int sign;
	t_stack *lista_cpy;

	i = 0;
	j = 0;
	sign = 0;
	count = 1;
	lista_cpy = lista;
	while (lista_cpy)
	{
		j = 0;
		while (tab[j])
		{
			if ((int)lista_cpy->num == tab[j])
			{
				sign = j - i;
				// printf("sign: %d i: %d j: %d\n", sign, i, j);
				if (sign > 0)
					handler("rra", &lista, &listb);
				if (sign < 0)
					handler("ra", &lista, &listb);
				if (sign == 0)
					handler("sa", &lista, &listb);
				// if (sign == -1)
				// 	handler("pa", &lista, &listb);
				// if (sign == 1)
				// 	handler("pb", &lista, &listb);
				count++;
				lista_cpy = lista;
				i = 0;
				ft_lstprint(lista, "a");
				ft_lstprint(listb, "b");
			}
			j++;
		}
		if (array_cmp(lista, tab) == 1)
			break;
		lista_cpy = lista_cpy->next;
		i++;
	}
	printf("count : %d\n", count);
	return (0);
}

int comb(t_stack *lista, t_stack *listb, int *tab)
{
	int i;
	int j;
	int count;
	int sign;
	t_stack *listb_cpy;

	i = 0;
	j = 0;
	sign = 0;
	count = 1;
	listb_cpy = listb;
	while (listb_cpy)
	{
		j = 0;
		while (tab[j])
		{
			if ((int)listb_cpy->num == tab[j])
			{
				sign = j - i;
				// printf("sign: %d i: %d j: %d\n", sign, i, j);
				if (sign > 1)
					handler("rrb", &lista, &listb);
				if (sign < -1)
					handler("rb", &lista, &listb);
				if (sign == 0)
					handler("sb", &lista, &listb);
				if (sign == -1)
					handler("pb", &lista, &listb);
				if (sign == 1)
					handler("pa", &lista, &listb);
				count++;
				listb_cpy = listb;
				i = 0;
				ft_lstprint(lista, "a");
				ft_lstprint(listb, "b");
			}
			j++;
		}
		if (array_cmp(lista, tab) == 1)
			break;
		listb_cpy = listb_cpy->next;
		i++;
	}
	printf("count : %d\n", count);
	return (0);
}

int compaire(t_stack *lista, t_stack *listb, int *tab)
{
	coma(lista, listb, tab);

	return (0);
}

int main(int ac, char **av)
{
	int *tab;
	t_stack *lista;
	t_stack *listb;

	(void)ac;
	lista = stack_arr(&av[1]);
	listb = NULL;

	tab = arg_to_arr(&av[1]);
	ft_lstprint(lista, "a");
	ft_lstprint(listb, "b");
	compaire(lista, listb, tab);
}