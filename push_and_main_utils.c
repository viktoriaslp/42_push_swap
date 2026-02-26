/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_main_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:31:00 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 17:15:08 by vslyunko         ###   ########.fr       */
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

t_stack	*find_lowest(t_stack *a)
{
	t_stack	*temp;
	t_stack	*lowest;

	temp = a->next;
	lowest = a;
	while (temp)
	{
		if (lowest->index > temp->index)
			lowest = temp;
		temp = temp->next;
	}
	return (lowest);
}
