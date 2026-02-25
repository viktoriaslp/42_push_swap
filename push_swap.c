#include "push_swap.h"

void    push_swap(t_stack **orig_a, t_stack **orig_b, int size_a)
{
    int size_b;

    set_index(*orig_a);
    while ((*orig_a)->next->next->next)
        pb(orig_a, orig_b);
    sort_three(orig_a);
    
    set_cur_pos(*orig_a);
    set_cur_pos(*orig_b);

    set_tar_pos(*orig_a, *orig_b);
    size_b = ft_lstsize(*orig_b);
    to_top_cost(*orig_b, size_b);

    t_stack *temp;
    temp = *orig_a;
    printf("a\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        printf("index: %i\n", temp->index );
        printf("pos: %i\n",temp->pos);
        printf("target_pos: %i\n", temp->target_pos);
        // printf("cost_a: %i\n",temp->cost_a);
        printf("cost_b: %i\n", temp->cost_b);
        // printf("next: %p\n", temp->next);
        printf("\n");
        temp = temp->next;
    }
    temp = *orig_b;
    printf("b\n");
    while (temp)
    {
        printf("value: %i\n", temp->value);
        printf("index: %i\n", temp->index );
        printf("pos: %i\n",temp->pos);
        printf("target_pos: %i\n", temp->target_pos);
        // printf("cost_a: %i\n",temp->cost_a);
        printf("cost_b: %i\n", temp->cost_b);
        // printf("next: %p\n", temp->next);
        printf("\n");

        temp = temp->next;
    }
}
