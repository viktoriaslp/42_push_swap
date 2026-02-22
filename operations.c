#include "push_swap.h"

void   swap(t_stack **a, t_stack **b)
{
    // if size > 1; iintercambiar 1er con 2do
    // imprimir sa/sb/ss.
    if (a && b)
        printf("ss");
    write(2, "\n", 1);
}

void   push(t_stack **a, t_stack **b)
{
    // if size > 0; iintercambiar 1eros ptr
    // imprimir pa/pb.
    write(2, "\n", 1);
}

void   rot(t_stack **a, t_stack **b)
{
    // if size > 3; 1st becomes last
    // imprimir ra/rb/rr.
    write(2, "\n", 1);
}

void   revrot(t_stack **a, t_stack **b)
{
    // if size > 3; last becomes 1st
    // imprimir rra/rrb/rrr.
    write(2, "\n", 1);
}