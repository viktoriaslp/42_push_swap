/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:28:44 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 17:35:28 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *a)
{
	t_stack	*node_to_set;
	t_stack	*node_to_com;
	int		index;

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

t_stack	*lowest_cost(t_stack *b)
{
	t_stack	*lowest;

	lowest = b;
	while (b)
	{
		if (lowest->total_cost > b->total_cost)
			lowest = b;
		b = b->next;
	}
	return (lowest);
}

void	do_rot(t_stack **a, t_stack **b, int rot_a, int rot_b)
{
	int	r_num;

	if (rot_a >= 0 && rot_b >= 0)
	{
		r_num = fc_min(rot_a, rot_b);
		rot_two_list(a, b, rr, r_num);
		if (rot_a > rot_b)
			rot_one_list(a, ra, rot_a, rot_b);
		else if (rot_a < rot_b)
			rot_one_list(b, rb, rot_b, rot_a);
	}
	else if (rot_a < 0 && rot_b < 0)
	{
		r_num = fc_min(rot_a, rot_b);
		rot_two_list(a, b, rrr, r_num);
		if (rot_a > rot_b)
			rot_one_list(a, rra, rot_a, rot_b);
		else if (rot_a < rot_b)
			rot_one_list(b, rrb, rot_b, rot_a);
	}
	else
		simple_rotate(a, b, rot_a, rot_b);
}

void	final_sort(t_stack **a, int size_a)
{
	t_stack	*lowest_node;

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

void	push_swap(t_stack **orig_a, t_stack **orig_b, int size_a)
{
	t_stack	*low_cost_node;
	int		size_b;

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
