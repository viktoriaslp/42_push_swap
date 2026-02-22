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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if(argc <= 1) 
        return (1);
    b = NULL;
    // Create stack a: parseo parametros y mostrar errores
    a = create_stack_a(argv + 1, argc - 1);
    if(a == NULL)
        return (1);
    // Sort ascending order using operations
    // func for 2 nbrs, func for 3 nbrs, func for size > 3.
    // Print while sorting
    a = sort_stack(a, b);
    return (0);
}