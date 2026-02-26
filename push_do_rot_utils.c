/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_do_rot_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:16:01 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 17:21:04 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_one_list(t_stack **list, void (*op)(t_stack **), int big, int small)
{
	int	n;

    big = fc_abs(big);
    small = fc_abs(small);
	n = big - small;
	while (n > 0)
	{
		op(list);
		n--;
	}
}

void	rot_two_list(t_stack **a, t_stack **b,
		void (*op)(t_stack **, t_stack **), int n)
{
	while (n > 0)
	{
		op(a, b);
		n--;
	}
}

void	simple_rotate(t_stack **a, t_stack **b, int rot_a, int rot_b)
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
