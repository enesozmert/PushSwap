/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:10 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:04:58 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rev_rotate_a(t_stack **lista, t_stack **listb)
{
	(void)listb;
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = *lista;
	back = *lista;
	front = *lista;
	if (*lista == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*lista = front;
}

void	rev_rotate_b(t_stack **lista, t_stack **listb)
{
	(void)lista;
	t_stack	*front;
	t_stack	*back;
	t_stack	*head;

	head = *listb;
	back = *listb;
	front = *listb;
	if (*listb == NULL)
		return ;
	while (front->next != NULL)
	{
		front = front->next;
		if (front->next != NULL)
			back = back->next;
	}
	if (front->next == NULL)
	{
		front->next = head;
		back->next = NULL;
	}
	*listb = front;
}

void	rev_rotate_rrr(t_stack **lista, t_stack **listb)
{
	rev_rotate_a(lista, listb);
	rev_rotate_b(lista, listb);
}
