#include "header.h"



int coma(t_stack *lista, t_stack *listb)
{
	int i;
	int j;
	int sign;
	int count;
	int *tab;
	t_stack *lista_cpy;

	i = 0; // list
	j = 0; // arr
	count = 0;
	sign = 0;
	lista_cpy = lista;
	tab = list_to_arr(lista);
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
				lista_cpy = lista;
				i = 0;
				tab = list_to_arr(lista);
				if (lista_cpy->num == find_min(tab))
				{
					handler("pb", &lista, &listb);
				}
				ft_lstprint(lista, "a");
				ft_lstprint(listb, "b");
				count++;
			}
			j++;
		}
		lista_cpy = lista_cpy->next;
		i++;
	}
	return (0);
}

int compaire(t_stack *lista, t_stack *listb)
{
	coma(lista, listb);

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
	compaire(lista, listb);
}