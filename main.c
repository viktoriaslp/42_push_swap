/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:41:50 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 17:41:28 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/* This program crates and sets to NULL two list stacks; 
 * checks received >2 parameters; Poblates stack_a from parameters, parsing 
 * and checking error, terminating if there are. Checks if is sorted, if not 
 * calculates the size to decide sorting technique. Sorting option if size=2; 
 * size=3; if size >3; Memory is freed if errors, is already sorted or at 
 * the end of the sort. */
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	create_stack_a(argv + 1, argc - 1, &a);
	if (a == NULL)
		return (1);
	if (is_sorted(a) == 1)
		end_clean(&a, &b);
	size_a = ft_lstsize(a);
	if (size_a == 2)
		sa(&a);
	else if (size_a == 3)
		sort_three(&a);
	else if (size_a == 5)
		sort_five(&a, &b);
	else
		push_swap(&a, &b, size_a);
	end_clean(&a, &b);
	return (0);
}
