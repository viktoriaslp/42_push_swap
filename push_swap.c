#include "push_swap.h"

void	rot_one_list(t_stack **list, void (*op)(t_stack **), int n)
{
	while (n > 0)
	{
		op(list);
		n--;
	}
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
			//rot_one_list(a, ra, r_times);
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

void    push_swap(t_stack **orig_a, t_stack **orig_b, int size_a)
{
    t_stack *low_cost_node;
    int     size_b;

    set_index(*orig_a);
    while ((*orig_a)->next->next->next)
        pb(orig_a, orig_b);
    sort_three(orig_a);
    while (*orig_b)
    {
    	size_b = ft_lstsize(*orig_b);
		size_a = ft_lstsize(*orig_a);
		set_cur_pos(*orig_a);
        set_cur_pos(*orig_b);
        set_tar_pos(*orig_a, *orig_b);
        cost_b(*orig_b, size_b);
        cost_a(*orig_b, size_a);
        set_total_cost(*orig_b, size_a, size_b);
        low_cost_node = lowest_cost(*orig_b);
        do_rot(orig_a, orig_b, low_cost_node->cost_a, low_cost_node->cost_b);
        pa(orig_b, orig_a);
    }
    final_sort(orig_a, size_a);
}
