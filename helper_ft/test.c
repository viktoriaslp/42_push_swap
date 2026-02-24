#include "../push_swap.h"

void    test(t_stack **a, t_stack **b)
{
    t_stack *temp;
    temp = a;
    printf("a\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        // printf("index: %i\n", temp->index );
        // printf("pos: %i\n",temp->pos);
        // printf("target_pos: %i\n", temp->target_pos);
        // printf("cost_a: %i\n",temp->cost_a);
        // printf("cost_b: %i\n", temp->cost_b);
        printf("next: %p\n\n", temp->next);
        temp = temp->next;
    }
    rra(&a);

    temp = a;
    printf("a\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        // printf("index: %i\n", temp->index );
        // printf("pos: %i\n",temp->pos);
        // printf("target_pos: %i\n", temp->target_pos);
        // printf("cost_a: %i\n",temp->cost_a);
        // printf("cost_b: %i\n", temp->cost_b);
        printf("next: %p\n\n", temp->next);
        temp = temp->next;
    }

    temp = b;
    printf("b\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        // printf("index: %i\n", temp->index );
        // printf("pos: %i\n",temp->pos);
        // printf("target_pos: %i\n", temp->target_pos);
        // printf("cost_a: %i\n",temp->cost_a);
        // printf("cost_b: %i\n", temp->cost_b);
        printf("next: %p\n\n", temp->next);
        temp = temp->next;
    }

    if (is_sorted(a) == 1) 
        printf("sorted succeded\n"); 
    t_stack *temp;
    temp = a;
    printf("a\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        printf("next: %p\n\n", temp->next);
        temp = temp->next;
    }  
}