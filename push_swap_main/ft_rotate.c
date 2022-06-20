/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:13 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:05:12 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rotate_a(t_stack **lista, t_stack **listb)
{
	(void)listb;
	t_stack *head;

	head = *lista;
	if (*lista == NULL)
		return ;
	while ((*lista)->next != NULL)
		*lista = (*lista)->next;
	(*lista)->next = head;
	head = head->next;
	*lista = (*lista)->next;
	(*lista)->next = NULL;
	*lista = head;
}

void	rotate_b(t_stack **lista, t_stack **listb)
{
	(void)lista;
	t_stack *head;

	head = *listb;
	if (*listb == NULL)
		return ;
	while ((*listb)->next != NULL)
		*listb = (*listb)->next;
	(*listb)->next = head;
	head = head->next;
	*listb = (*listb)->next;
	(*listb)->next = NULL;
	*listb = head;
}

void	rotate_rr(t_stack **lista, t_stack **listb)
{
	rotate_a(lista, listb);
	rotate_b(lista, listb);
}
