#include "header.h"

static void count_sort(t_stack **lista, t_stack **listb, int digit, int *count_move)
{
	int i;
	int count_a;
	int count_b;

	i = 0;
	count_a = list_size(*lista);
	count_b = list_size(*listb);
	if (list_size(*listb) > 0)
	{
		count_b = list_size(*listb);
		while (i < count_b)
		{
			if ((*listb)->binary[digit] == 1)
			{
				handler("pa", lista, listb);
				(*count_move)++;
			}
			else
			{
				handler("rb", lista, listb);
				(*count_move)++;
			}
			i++;
		}
	}
	if (list_size(*lista) > 0)
	{
		i = 0;
		count_a = list_size(*lista);
		while (i < count_a)
		{
			if (is_sorted(*lista) && is_rev_sorted(*listb))
				return;
			if ((*lista)->binary[digit] == 0)
			{
				handler("pb", lista, listb);
				(*count_move)++;
			}
			else
			{
				handler("ra", lista, listb);
				(*count_move)++;
			}
			i++;
		}
	}
}

void hard_solve(t_stack **lista, t_stack **listb)
{
	int i;
	int max_bits;
	int count_move;

	i = 0;
	max_bits = 0;
	count_move = 0;
	while (list_size(*lista) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		// printf("i : %d, max_bits %d", i, max_bits);
		// if (i == max_bits - 1)
		// {
		// 	exit (0);
		// 	// end_sort(lista, listb, 8 - i, &count_move);
		// }
		// else
		count_sort(lista, listb, 8 - i, &count_move);
		if (is_sorted(*lista) && is_rev_sorted(*listb))
		{
			while (list_size(*listb) > 0)
			{
				handler("pa", lista, listb);
				(count_move)++;
			}
		}
		i++;
	}
	// printf("count move %d\n", count_move);
}
