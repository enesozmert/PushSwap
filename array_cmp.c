#include "header.h"

int array_cmp(t_stack *list, int *tab)
{
    int i;
    int flag;
    t_stack *list_cpy;

    i = 0;
    flag = 0;
    list_cpy = list;
    while (list_cpy)
    {
        if (list_cpy->num == tab[i])
            flag = 1;
        else
            return (0);
        list_cpy = list_cpy->next;
        i++;
    }
    return (flag);
}