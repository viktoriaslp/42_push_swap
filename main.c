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
	else
		push_swap(&a, &b, size_a);

		t_stack *temp;
		temp = a;
		printf("a\n");
		while (temp)
		{
			// printf("value: %i\n", temp->value);
			printf("index: %i\n", temp->index );
			// printf("pos: %i\n",temp->pos);
			// printf("target_pos: %i\n", temp->target_pos);
			// printf("cost_a: %i\n",temp->cost_a);
			// printf("cost_b: %i\n", temp->cost_b);
			// printf("total_cost: %i\n", temp->total_cost); 
			// printf("next: %p\n", temp->next);
			printf("\n");
			temp = temp->next;
		}
	
	end_clean(&a, &b);
	return (0);
}
