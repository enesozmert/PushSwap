/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:31 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:54:19 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(t_stack *list)
{
	int	nothing;

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

int	is_rev_sorted(t_stack *list)
{
	int	nothing;

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

int	*list_to_arr(t_stack *list)
{
	int			i;
	int			c;
	int			*tab;
	t_stack		*list_cpy;

	i = 0;
	c = 0;
	list_cpy = list;
	while (list_cpy)
	{
		list_cpy = list_cpy->next;
		i++;
	}
	tab = (int *)malloc(sizeof(int) * i);
	i = 0;
	list_cpy = list;
	while (list_cpy)
	{
		tab[c] = list_cpy->num;
		list_cpy = list_cpy->next;
		c++;
		i++;
	}
	quick_sort(tab, 0, i - 1);
	return (tab);
}
