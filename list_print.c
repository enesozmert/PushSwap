/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:34 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:54:52 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_list_print(t_stack *lst, char *name)
{
	int	size;

	size = 0;
	printf("num: \n %s : ", name);
	while (lst)
	{
		printf("%d", lst->num);
		if (lst->next)
			printf("->");
		lst = lst->next;
		size++;
	}
	printf("\n");
}

void	ft_list_index_print(t_stack *lst, char *name)
{
	int	size;

	size = 0;
	printf("num: \n %s : ", name);
	while (lst)
	{
		printf("index: %d", lst->index);
		if (lst->next)
			printf("->");
		lst = lst->next;
		size++;
	}
	printf("\n");
}

void	ft_list_binary_print(t_stack *lst, char *name)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	printf("num: \n %s : ", name);
	while (lst)
	{
		while (i < 9)
		{
			printf("%d", lst->binary[i]);
			i++;
		}
		i = 0;
		printf(" ");
		if (lst->next)
			printf("->");
		if (size % 2 == 0)
			printf("\n");
		lst = lst->next;
		size++;
	}
	printf("\n");
}
