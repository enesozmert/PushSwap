/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozmert <eozmert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:59:47 by eozmert           #+#    #+#             */
/*   Updated: 2022/06/20 16:40:31 by eozmert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int *arg_to_arr(char **str)
{
    int i;
    int len;
    int c;
    int *tab;

    i = 1;
    c = 0;
    len = 0;
    while (str[len])
        len++;
    tab = (int *)malloc(sizeof(int) * (len - 2));
    while (str[i])
    {
        tab[c] = ft_atoi(str[i]);
        c++;
        i++;
    }
    return (tab);
}
