#include "header.h"

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
	return (sum1 > sum2);
}

int main(int ac, char **av)
{
	t_stack *lista;
	t_stack *listb;

	if (ac < 2)
		return (0);
	if (check_error(&av[1]) || check_dup(av))
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	lista = stack_arr(&av[1]);
	listb = NULL;
	if (ac == 4)
		basic_solve(&lista, &listb);
	else if (ac == 6)
		medium_solve(&lista, &listb);
	else
		hard_solve(&lista, &listb);

	// ft_list_print(lista, "a");
	// ft_list_print(listb, "b");
	// ft_list_index_print(lista, "a");
	// ft_list_index_print(listb, "b");
	// ft_list_binary_print(lista, "a");
	// ft_list_binary_print(listb, "b");
	// if (is_sorted(lista))
	// {
	// 	printf("okey\n");
	// }
	// else
	// 	printf("nokey\n");
	// write_file();
	// compaire(&lista, &listb);
}