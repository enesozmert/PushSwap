/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_solve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:23 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:00:23 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void count_sort(t_stack **lista, t_stack **listb, int digit)
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
				handler("pa", lista, listb);
			else
				handler("rb", lista, listb);
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
				handler("pb", lista, listb);
			else
				handler("ra", lista, listb);
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
		count_sort(lista, listb, 8 - i);
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
}
