/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_set_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:39:36 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:46:10 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cur_pos(t_stack *head)
{
	t_stack	*node_to_set;
	t_stack	*node_to_com;
	int		pos;

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

void	set_tar_pos(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	t_stack	*lowest;
	int		best_index;

	lowest = find_lowest(a);
	temp = a;
	while (b)
	{
		a = temp;
		best_index = -1;
		b->target_pos = -1;
		while (a)
		{
			if (b->index < a->index
				&& (b->target_pos == -1 || best_index > a->index))
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

void	cost_b(t_stack *list, int size)
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

void	cost_a(t_stack *list, int size)
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

void	set_total_cost(t_stack *b)
{
	while (b)
	{
		if ((b->cost_a >= 0 && b->cost_b >= 0)
			|| (b->cost_a < 0 && b->cost_b < 0))
			b->total_cost = fc_max(b->cost_a, b->cost_b);
		else
		{
			b->total_cost = fc_abs(b->cost_a) + fc_abs(b->cost_b);
		}
		b = b->next;
	}
}
