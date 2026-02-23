#include "push_swap.h"

void    swap(t_stack **list)
{
    t_stack *tmp;

    tmp = *list;
    *list = tmp->next;
    tmp->next = (*list)->next;
    (*list)->next = tmp;
}

void    swapa(t_stack **a, t_stack **b)
{
    // if size > 1; iintercambiar 1er con 2do
    // imprimir sa/sb/ss.
    if (a && b)
        printf("ss");
    write(2, "\n", 1);
}

void    push(t_stack **frst, t_stack **scnd)
{
    t_stack *tmp;

    tmp = *frst;
    *frst = *scnd;
    *scnd = tmp;
    tmp = (*frst)->next;
    (*frst)->next = (*scnd)->next;
    (*scnd)->next = tmp;
}

void   pusha(t_stack **a, t_stack **b)
{
    // if size > 0; iintercambiar 1eros ptr
    // imprimir pa/pb.
    write(2, "\n", 1);
}

void    rotate(t_stack **list)
{
    t_stack *tmp;
    t_stack *last;

    tmp = *list;
    *list = (*list)->next;
    last = *list;
    while (last->next)
        last = last->next;
    last->next = tmp;
    tmp->next = NULL;
}

void   rot(t_stack **a, t_stack **b)
{
    // if size > 3; 1st becomes last
    // imprimir ra/rb/rr.
    write(2, "\n", 1);
}

void    reverse(t_stack **list)
{
    t_stack *tmp;
    t_stack *scndlast;

    tmp = *list;
    scndlast = *list;
    while (scndlast->next->next)
        scndlast = scndlast->next;
    *list = scndlast->next;
    scndlast->next->next = tmp;
    scndlast->next = NULL;
}

void   revrot(t_stack **a, t_stack **b)
{
    // if size > 3; last becomes 1st
    // imprimir rra/rrb/rrr.
    write(2, "\n", 1);
}