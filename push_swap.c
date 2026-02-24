/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:41:50 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/02 14:41:53 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    size_t  size_a;
    size_t  size_b;

    if(argc < 2) 
        return (1);
    a = NULL;
    b = NULL;
    // Create stack a: parseo parametros, si errores terminar y salir.
    create_stack_a(argv + 1, argc - 1, &a);
    if(a == NULL)
        return (1);
    // Check if it is already sorted.
    if (is_sorted(a) == 1)
        end_clean(&a, &b);
    // If it needs to be sorted check the list size.
    size_a = ft_lstsize(a);
    size_b = ft_lstsize(b);
    // Sort for 2 elements
    if (size_a == 2)
        sa(&a);
    // Sort for3 elements
    if (size_a == 3)
        sort_three(&a);

    end_clean(&a, &b);
    return (0);
}
