#include "push_swap.h"

void    set_cur_pos(t_stack *head)
{
    t_stack *node_to_set;
    t_stack *node_to_com;
    int     pos;

    node_to_set = head;
    while (node_to_set)
    {
        node_to_com = head;
        pos = 0;
        while (node_to_com && node_to_set != node_to_com)
        {
            pos++;
            node_to_com = node_to_com->next;
        }
        node_to_set->pos = pos;
        node_to_set = node_to_set->next;
    }
}

void    set_tar_pos(t_stack *a, t_stack *b)
{
    int lowest;
    t_stack *temp;

    temp = a->next;
    lowest = a->index;
    while (temp)
    {
        if (lowest > temp->index)
            lowest = temp->index;
        temp = temp->next;
    }
    printf("lowest: %i\n", lowest);
    temp = a;
    while (b)
    {
        a = temp;
        b->target_pos = -1;
        while (a)
        {
            if (b->index < a->index && (b->target_pos > a->index || b->target_pos == -1))
                b->target_pos = a->index;
            a = a->next;
        }
        if (b->target_pos == -1)
            b->target_pos = lowest;
        b = b->next;
    }
}

void    to_top_cost(t_stack *list, int size)
{
    while (list)
    {
        if (list->pos <= size / 2)
            list->cost_b = list->pos;
        else
            list->cost_b = size - list->pos;
        list = list->next;
    }
}
