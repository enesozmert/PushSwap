#include "header.h"

void		push_a(t_stack **lista, t_stack **listb)
{
	t_stack *bot_b;

	if (*listb == NULL)
		return ;
	bot_b = (*listb)->next;
	(*listb)->next = *lista;
	*lista = *listb;
	*listb = bot_b;
}

void		push_b(t_stack **lista, t_stack **listb)
{
	t_stack *bot_a;

	if (*lista == NULL)
		return ;
	bot_a = (*lista)->next;
	(*lista)->next = *listb;
	*listb = *lista;
	*lista = bot_a;
}