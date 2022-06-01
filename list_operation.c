#include "header.h"

int tab_avg(t_stack *list)
{
    int i;
    int avg;
    t_stack *list_cpy;


    i = 0;
    avg = 0;
    list_cpy = list;
    while (list_cpy)
    {
        avg += list_cpy->num;
        list_cpy = list_cpy->next;
        i++;
    }
    avg = avg / i;
    return (avg);
}