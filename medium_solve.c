#include "header.h"

static void count_sort(t_stack **lista, t_stack **listb, int *count_move)
{
    int i;
    int count_a;
    int count_b;

    i = 0;
    count_a = list_size(*lista);
    count_b = list_size(*listb);
    if (list_size(*lista) > 0)
    {
        i = 0;
        count_a = list_size(*lista);
        while (i < list_size(*lista))
        {
            if (is_sorted(*lista) && is_rev_sorted(*listb))
                return;
            if ((*lista)->index == 0 || (*lista)->index == 1)
            {
                handler("pb", lista, listb);
                (*count_move)++;
            }
            else
            {
                handler("ra", lista, listb);
                (*count_move)++;
            }
            i++;
        }
    }
}

void medium_solve(t_stack **lista, t_stack **listb)
{
    int count_move;

    count_move = 0;
    count_sort(lista, listb, &count_move);
}