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
				printf("sign %d\n", sign);
				if (sign > 0)
					handler("ra", lista, NULL);
				if (sign < 0)
					handler("rra", lista, NULL);
				if (sign == 0)
					handler("sa", lista, NULL);
				// tab = list_to_arr(*lista);
				count++;
			}
			j++;
		}
		lista_cpy = lista_cpy->next;
		i++;
	}
}

void comb(t_stack **listb)
{
	int i;
	int j;
	int sign;
	int count;
	int *tab;
	t_stack *listb_cpy;

	i = 0;
	count = 0;
	sign = 0;
	listb_cpy = *listb;

	tab = list_to_arr(*listb);
	while (listb_cpy)
	{
		j = 0;
		while (tab[j])
		{
			if (listb_cpy->num == tab[j])
			{
				sign = j - i;
				printf("sign %d\n", sign);
				if (sign > 0)
					handler("rb", NULL, listb);
				if (sign < 0)
					handler("rrb", NULL, listb);
				if (sign == 0)
					handler("sb", NULL, listb);
				tab = list_to_arr(*listb);
				count++;
			}
			j++;
		}
		listb_cpy = listb_cpy->next;
		i++;
	}
}

int compaire(t_stack **lista, t_stack **listb)
{
	(void)listb;
	(void)lista;
	return (0);
}

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

int binary_of_zero(t_stack *lista, int index)
{
	t_stack *temp;
	temp = lista;
	while (temp)
	{
		if (temp->binary[index] == 0)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int find_sum(t_stack **lista, int digit)
{
	t_stack *lista_cpy;
	int i;
	int count;
	int sum1;
	int sum2;

	sum1 = 0;
	sum2 = 0;
	i = 0;
	count = list_size(*lista);
	lista_cpy = *lista;
	while (i < count / 2)
	{
		if (lista_cpy->binary[digit] == 1)
			sum1++;
		i++;
		lista_cpy = lista_cpy->next;
	}
	while (i < count / 2)
	{
		if (lista_cpy->binary[digit] == 1)
			sum2++;
		i++;
	}
	// printf("sum1: %d\n", sum1);
	// printf("sum2: %d\n", sum2);
	return (sum1 > sum2);
}

void list_sort(t_stack **lista, t_stack **listb)
{
	int i;
	// int j;
	int l;
	int max_bits;
	// t_stack *lista_cpy;
	t_stack *listb_cpy;

	i = 0;
	// j = 0;
	l = 0;
	max_bits = 0;
	// lista_cpy = *lista;
	listb_cpy = *listb;
	while ((list_size(*lista) - 1) >> max_bits != 0)
	{
		max_bits++;
	}
	printf("max bits %d\n", max_bits);
	while (l < 5)
	{
		while (i < max_bits)
		{
			while (binary_of_zero(*lista, 8 - i) == 0)
			{
				if ((*lista)->binary[8 - i] == 0)
				{
					handler("pb", lista, listb);
					listb_cpy = *listb;
				}
				else
				{
					handler("ra", lista, listb);
				}
			}
			ft_list_print(*lista, "a");
			ft_list_print(*listb, "b");
			ft_list_index_print(*lista, "a");
			ft_list_index_print(*listb, "b");
			ft_list_binary_print(*lista, "a");
			ft_list_binary_print(*listb, "b");
			i++;
		}
		l++;
	}

	listb_cpy = *listb;
	while (listb_cpy)
	{
		handler("pa", lista, listb);
		listb_cpy = listb_cpy->next;
	}
}

int main(int ac, char **av)
{
	t_stack *lista;
	t_stack *listb;
	// char **argv;
	
	(void)ac;
	// argv = fill_args(ac, av);
	// check_double(argv, -1, -1);
	// check_number(argv, -1, -1);
	lista = stack_arr(&av[1]);
	listb = NULL;
	hard_solve(&lista, &listb);

	// list_sort(&lista, &listb);
	// ft_list_print(lista, "a");
	// ft_list_print(listb, "b");
	// ft_list_index_print(lista, "a");
	// ft_list_index_print(listb, "b");
	// ft_list_binary_print(lista, "a");
	// ft_list_binary_print(listb, "b");
	// compaire(&lista, &listb);

	// if (is_sorted(lista))
	// {
	// 	printf("okey\n");
	// }
	// else
	// 	printf("nokey\n");
}