#include "push_swap.h"

void    push_swap(t_stack **orig_a, t_stack **orig_b, int size_a)
{
    int     size_b;
    t_stack *low_cost_node;

    set_index(*orig_a);
    while ((*orig_a)->next->next->next)
        pb(orig_a, orig_b);
    sort_three(orig_a);
    
    while (*orig_b)
    {
        // Find target node
        set_cur_pos(*orig_a);
        set_cur_pos(*orig_b);

        set_tar_pos(*orig_a, *orig_b);
        size_b = ft_lstsize(*orig_b);
        cost_b(*orig_b, size_b);
        size_a = ft_lstsize(*orig_a);
        cost_a(*orig_b, size_a);
        // Calculate cheapest node
        set_total_cost(*orig_b, size_a, size_b);
        low_cost_node = lowest_cost(*orig_b);
        do_rot(orig_a, orig_b, low_cost_node->cost_a, low_cost_node->cost_b);
        pa(orig_b, orig_a);
    }

    // final step to rotate the list
    final_sort(orig_a, size_a);

    // t_stack *temp;
    // temp = *orig_a;
    // printf("a\n");
    // while (temp)
    // {
    //     printf("value: %i\n", temp->value);
    //     printf("index: %i\n", temp->index );
    //     printf("pos: %i\n",temp->pos);
    //     printf("target_pos: %i\n", temp->target_pos);
    //     printf("cost_a: %i\n",temp->cost_a);
    //     printf("cost_b: %i\n", temp->cost_b);
    //     printf("total_cost: %i\n", temp->total_cost); 
    //     // printf("next: %p\n", temp->next);
    //     printf("\n");
    //     temp = temp->next;
    // }
    // temp = *orig_b;
    // printf("b\n");
    // while (temp)
    // {
    //     printf("value: %i\n", temp->value);
    //     printf("index: %i\n", temp->index );
    //     printf("pos: %i\n",temp->pos);
    //     printf("target_pos: %i\n", temp->target_pos);
    //     printf("cost_a: %i\n",temp->cost_a);
    //     printf("cost_b: %i\n", temp->cost_b);
    //     printf("total_cost: %i\n", temp->total_cost);
    //     printf("\n");

    //     temp = temp->next;
    // }
}
