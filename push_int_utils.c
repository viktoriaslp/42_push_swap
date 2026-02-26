/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_int_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:41:58 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 17:45:03 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fc_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	fc_max(int x, int y)
{
	x = fc_abs(x);
	y = fc_abs(y);
	if (x > y)
		return (x);
	else
		return (y);
}

int	fc_min(int x, int y)
{
	x = fc_abs(x);
	y = fc_abs(y);
	if (x < y)
		return (x);
	else
		return (y);
}
