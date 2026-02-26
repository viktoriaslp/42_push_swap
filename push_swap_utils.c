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
    t_stack *temp;
    t_stack *lowest;
    int     best_index;

    lowest = find_lowest(a);
    temp = a;
    while (b)
    {
        a = temp;
        best_index = -1;
        b->target_pos = -1;
        while (a)
        {
            if (b->index < a->index && (b->target_pos == -1 || best_index > a->index))
            {
                b->target_pos = a->pos;
                best_index = a->index;
            }
            a = a->next;
        }
        if (b->target_pos == -1)
            b->target_pos = lowest->pos;
        b = b->next;
    }
}

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

void    cost_b(t_stack *list, int size)
{
    while (list)
    {
        if (list->pos <= size / 2)
            list->cost_b = list->pos;
        else
            list->cost_b = list->pos - size;
        list = list->next;
    }
}

void    cost_a(t_stack *list, int size)
{
    while (list)
    {
        if (list->target_pos <= size / 2)
            list->cost_a = list->target_pos;
        else
            list->cost_a = list->target_pos - size;
        list = list->next;
    }
}

void    set_total_cost(t_stack *b, int size_a, int size_b)
{
    while (b)
    {
        if ((b->cost_a >= 0 && b->cost_b >= 0) || (b->cost_a < 0 && b->cost_b < 0))
            b->total_cost = fc_max(b->cost_a, b->cost_b);
        else
        {
            b->total_cost = fc_abs(b->cost_a) + fc_abs(b->cost_b); // Check is is allowed 2 func inside one line.
        }
        b = b->next;
    }
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

void    do_rot(t_stack **a, t_stack **b, int rot_a, int rot_b)
{
    int rr_times;
    int r_times;
    if (rot_a >= 0 && rot_b >= 0)
    {
        rr_times = fc_min(rot_a, rot_b);
        while (rr_times > 0)
        {
            rr(a, b);
            rr_times--;
        }
        if (rot_a > rot_b)
        {
            r_times = rot_a - rot_b;
            while (r_times > 0)
            {
                ra(a);
                r_times--;
            }
        }
        else if (rot_a < rot_b)
        {
            r_times = rot_b - rot_a;
            while (r_times > 0)
            {
                rb(b);
                r_times--;
            }
        }
    }
    else if (rot_a < 0 && rot_b < 0)
    {
        rr_times = fc_min(rot_a, rot_b);
        while (rr_times > 0)
        {
            rrr(a, b);
            rr_times--;
        }
        rot_a = fc_abs(rot_a);
        rot_b = fc_abs(rot_b);
        if (rot_a > rot_b)
        {
            r_times = rot_a - rot_b;
            while (r_times > 0)
            {
                rra(a);
                r_times--;
            }
        }
        else if (rot_a < rot_b)
        {
            r_times = rot_b - rot_a;
            while (r_times > 0)
            {
                rrb(b);
                r_times--;
            }
        }
    }
    else
    {
        while (rot_a > 0)
        {
            ra(a);
            rot_a--;
        }
        while (rot_a < 0) 
        {
            rra(a);
            rot_a++;
        }
        while (rot_b > 0)
        {
            rb(b);
            rot_b--;
        }
        while (rot_b < 0) 
        {
            rrb(b);
            rot_b++;
        }
    }
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

void    final_sort(t_stack **a, int size_a)
{
    t_stack *lowest_node;

    lowest_node = find_lowest(*a);
    while (lowest_node->pos != 0)
    {
        if (lowest_node->pos < size_a / 2)
            ra(a);
        else
            rra(a);
        set_cur_pos(*a);
    }
}