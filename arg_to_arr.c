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
    tab = (int *)malloc(sizeof(int) * (len));
    while (str[i])
    {
        tab[c] = ft_atoi(str[i]);
        c++;
        i++;
    }
    //quick_sort(tab, 0, len - 1);
    return (tab);
}