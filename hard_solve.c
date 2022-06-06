
#include "header.h"

static void final_move(t_stack **lista, t_stack **listb, int i)
{
	int cnt[2];

	cnt[0] = 0;
	cnt[1] = list_size(*lista);
	while (cnt[0]++ < cnt[1])
	{
		if ((*lista)->binary[i] == 0)
			handler("pb", lista, listb);
		else
			handler("ra", lista, listb);
	}
	while (list_size(*listb) > 0)
		handler("pa", lista, listb);
}

static void sub(t_stack **lista, t_stack **listb, int i, int cnt[2])
{
	cnt[1] = list_size(*listb);
	while (cnt[0]++ < cnt[1])
	{
		if ((*lista)->binary[i] == 1)
			handler("pa", lista, listb);
		else
			handler("rb", lista, listb);
	}
	while (list_size(*listb) > 0)
		handler("pa", lista, listb);
}

static void normal_move(t_stack **lista, t_stack **listb, int i)
{
	int cnt[2];

	cnt[0] = 0;
	if (list_size(*lista) > 0)
	{
		cnt[1] = list_size(*lista);
		while (cnt[0]++ < cnt[1])
		{
			if ((*lista)->binary[i] == 0)
				handler("pb", lista, listb);
			else
				handler("ra", lista, listb);
		}
		while (list_size(*lista) > 0)
			handler("pb", lista, listb);
	}
	else
		sub(lista, listb, i, cnt);
}

void hard_solve(t_stack **lista, t_stack **listb)
{
	int i;
	int max_bits;

	i = 0;
	max_bits = 0;
	while ((list_size(*lista) - 1) >> max_bits != 0)
		max_bits++;
	while (i < max_bits)
	{
		if (i == max_bits && i % 2)
			final_move(lista, listb, 8 - i);
		else
			normal_move(lista, listb, 8 - i);
		i++;
	}
}