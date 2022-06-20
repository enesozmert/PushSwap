/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:07 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:04:53 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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