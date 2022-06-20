/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:00:29 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:46:40 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_overflow(char *str)
{
	long long	num;

	num = ft_atoi_long(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int	check_error(char **av)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			c = av[i][j];
			if (ft_isalpha(c) || (c >= 33 && c <= 43) || (c >= 58 && c <= 64))
				return (1);
		}
		if (check_overflow(av[i]))
			return (1);
	}
	return (0);
}

int	check_dup(char **av)
{
	int	*arr;
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	arr = arg_to_arr(av);
	while (av[size])
		++size;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == arr[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
