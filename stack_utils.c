#include "push_swap.h"

int is_sorted(t_stack *list)
{
    t_stack *nextone;
    while (list && list->next)
    {
        nextone = list->next;
        while (nextone)
        {
            if (list->value > nextone->value)
                return (0);
            nextone = nextone->next;
        }
        list = list->next;
    }
    return (1);
}

void    end_clean(t_stack **list_a, t_stack **list_b)
{
    if (list_a)
        free_list(list_a);
    if (list_b)
        free_list(list_b);
    exit (0);
}

void    sort_three(t_stack **list)
{
    int higest;
    t_stack *temp;

    temp = (*list)->next;
    higest = (*list)->value;
    while (temp)
    {
        if (higest < temp->value)
            higest = temp->value;
        temp = temp->next;
    }
    if ((*list)->value == higest)
        ra(list);
    else if ((*list)->next->value == higest)
        rra(list);
    if ((*list)->value > (*list)->next->value)
        sa(list);
}

void    set_index(t_stack *a)
{
    t_stack *node_to_set;
    t_stack *node_to_com;
    int     index;

    node_to_set = a;
    while (node_to_set)
    {
        node_to_com = a;
        index = 0;
        while (node_to_com)
        {
            if (node_to_set->value > node_to_com->value)
                index++;
            node_to_com = node_to_com->next;
        }
        node_to_set->index = index;
        node_to_set = node_to_set->next;
    }
}