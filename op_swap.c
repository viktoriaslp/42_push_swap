/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:11:48 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:15:12 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **list)
{
	t_stack	*tmp;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	*list = tmp->next;
	tmp->next = (*list)->next;
	(*list)->next = tmp;
}

void	sa(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
