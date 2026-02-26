/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:31:00 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:36:04 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *list)
{
	t_stack	*nextone;

	while (list && list->next)
	{
		nextone = list->next;
		while (nextone)
		{
			if (list->value > nextone->value)
				return (0);
			nextone = nextone->next;
		}
		list = list->next;
	}
	return (1);
}

void	sort_three(t_stack **list)
{
	int		higest;
	t_stack	*temp;

	temp = (*list)->next;
	higest = (*list)->value;
	while (temp)
	{
		if (higest < temp->value)
			higest = temp->value;
		temp = temp->next;
	}
	if ((*list)->value == higest)
		ra(list);
	else if ((*list)->next->value == higest)
		rra(list);
	if ((*list)->value > (*list)->next->value)
		sa(list);
}

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
