#include "header.h"

int compaire(t_stack **lista, t_stack **listb, int ac)
{
	if (ac == 4)
		basic_solve(&lista, &listb);
	else if (ac == 6)
		medium_solve(&lista, &listb);
	else
		hard_solve(&lista, &listb);
	return (0);
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
	compaire(&lista, &listb, ac);
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
}