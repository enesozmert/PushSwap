#include "header.h"

static void count_sort(t_stack **lista, t_stack **listb)
{
    int i;

    i = 0;
    if (list_size(*lista) > 0)
    {
        while (i < list_size(*lista) * 2)
        {
            if ((*lista)->index == 0 || (*lista)->index == 1)
            {
                handler("pb", lista, listb);
            }
            else if ((*lista)->next->index == 0 || (*lista)->next->index == 1)
            {
                handler("sa", lista, listb);
            }
            else
            {
                handler("ra", lista, listb);
            }

            i++;
        }
    }
    if (list_size(*listb) > 1)
    {
        if ((*listb)->index < (*listb)->next->index)
        {
            handler("sb", lista, listb);
        }
    }
}

void medium_solve(t_stack **lista, t_stack **listb)
{
    int count_move;

    count_move = 0;
    count_sort(lista, listb);
    basic_solve(lista, listb);
    while (list_size(*listb) > 0)
    {
        handler("pa", lista, listb);
        (count_move)++;
    }
}