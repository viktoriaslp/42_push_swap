#include "push_swap.h"

t_stack *find_lowest(t_stack *a)
{
    t_stack *temp;
    t_stack *lowest;

    temp = a->next;
    lowest = a;
    while (temp)
    {
        if (lowest->index > temp->index)
            lowest = temp;
        temp = temp->next;
    }
    return (lowest);
}

t_stack *lowest_cost(t_stack *b)
{
    t_stack *lowest;

    lowest = b;
    while(b)
    {
        if (lowest->total_cost > b->total_cost)
            lowest = b;
        b = b->next;
    }
    return (lowest);
}


int fc_abs(int x)
{
    if (x < 0)
        return (-x);
    return (x);
}

int fc_max(int x, int y)
{
    x = fc_abs(x);
    y = fc_abs(y);
    if (x > y)
        return (x);
    else
        return (y);
}

int fc_min(int x, int y)
{
    x = fc_abs(x);
    y = fc_abs(y);
    if (x < y)
        return (x);
    else
        return (y);
}

