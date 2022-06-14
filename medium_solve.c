
#include "header.h"

static void count_sort(t_stack **lista, t_stack **listb)
{
    if ((*lista)->index > (*lista)->next->index
    && (*lista)->index < (*lista)->next->next->index) // 2 1 3
        handler("sa", lista, listb);
    else if ((*lista)->index > (*lista)->next->index
    && (*lista)->next->index > (*lista)->next->next->index) // 3 2 1
    {
        handler("sa", lista, listb);
        handler("rra",lista, listb);
    }
    else if ((*lista)->index > (*lista)->next->index
    && (*lista)->next->index < (*lista)->next->next->index) // 3 1 2
        handler("ra", lista, listb);
    else if ((*lista)->index < (*lista)->next->index
    && (*lista)->index < (*lista)->next->next->index) // 1 3 2
    {
        handler("sa", lista, listb);
        handler("ra", lista, listb);
    }
    else if ((*lista)->next->next->index < (*lista)->index
    && (*lista)->index < (*lista)->next->index) // 2 3 1
        handler("rra", lista, listb);
}

void medium_solve(t_stack **lista, t_stack **listb)
{
    count_sort(lista, listb);
}
