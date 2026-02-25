#include "push_swap.h"

void    swap(t_stack **list)
{
    t_stack *tmp;

    if (!list || !*list || !(*list)->next)
        return ;
    tmp = *list;
    *list = tmp->next;
    tmp->next = (*list)->next;
    (*list)->next = tmp;
}

void    sa(t_stack **a)
{
    if (!a || !*a || !(*a)->next)
        return ;
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    if (!b || !*b || !(*b)->next)
        return ;
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    if (!a || !*a || !(*a)->next)
        return ;
    swap(a);
    swap(b);  //TODO: imprime si solo hace un swap
    write(1, "ss\n", 3);
}

void    push(t_stack **from, t_stack **to)
{
    t_stack *tmp;

    if (!from || !*from)
        return ;
    tmp = (*from)->next;
    (*from)->next = *to;
    *to = *from;
    *from = tmp;
}

void   pa(t_stack **b, t_stack **a)
{
    push(b, a);
    write(1, "pa\n", 3);
}
void   pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}

void    rotate(t_stack **list)
{
    t_stack *tmp;
    t_stack *last;

    if (!list || !*list || !(*list)->next)
        return ;
    tmp = *list;
    *list = (*list)->next;
    last = *list;
    while (last->next)
        last = last->next;
    last->next = tmp;
    tmp->next = NULL;
}

void   ra(t_stack **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}
void   rb(t_stack **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}
void   rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}

void    reverse(t_stack **list)
{
    t_stack *tmp;
    t_stack *scndlast;

    if (!list || !*list || !(*list)->next)
        return ;
    tmp = *list;
    scndlast = *list;
    while (scndlast->next->next)
        scndlast = scndlast->next;
    *list = scndlast->next;
    scndlast->next->next = tmp;
    scndlast->next = NULL;
}

void   rra(t_stack **a)
{
    reverse(a);
    write(1, "rra\n", 4);
}

void   rrb(t_stack **b)
{
    reverse(b);
    write(1, "rrb\n", 4);
}

void   rrr(t_stack **a, t_stack **b)
{
    reverse(a);
    reverse(b);
    write(1, "rrr\n", 4);
}
