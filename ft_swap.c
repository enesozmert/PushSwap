#include "header.h"

void	swap_a(t_stack **lista, t_stack **listb)
{
	(void)listb;
	t_stack *temp;

	if (*lista == NULL)
		return ;
	temp = *lista;
	*lista = (*lista)->next;
	temp->next = (*lista)->next;
	(*lista)->next = temp;
}

void	swap_b(t_stack **lista, t_stack **listb)
{
	(void)lista;
	t_stack *temp;

	if (*listb == NULL)
		return ;
	temp = *listb;
	*listb = (*listb)->next;
	temp->next = (*listb)->next;
	(*listb)->next = temp;
}

void	swap_ss(t_stack **lista, t_stack **listb)
{
	swap_a(lista, listb);
	swap_b(lista, listb);
}
