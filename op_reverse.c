/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:23:52 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:25:57 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **list)
{
	t_stack	*tmp;
	t_stack	*scndlast;

	if (!list || !*list || !(*list)->next)
		return ;
	tmp = *list;
	scndlast = *list;
	while (scndlast->next->next)
		scndlast = scndlast->next;
	*list = scndlast->next;
	scndlast->next->next = tmp;
	scndlast->next = NULL;
}

void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
