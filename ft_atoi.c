/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:54:30 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/17 11:22:14 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	atoi_strict(const char *nptr, int *nbr)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if ((nptr[0] == '-' || nptr[0] == '+') && (nptr[1] >= '0' && nptr[1] <= '9'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[0] == '-')
		nb *= -1;
	if ((nptr[i] != '\0' || nptr[0] == '\0') || (nb < -2147483648 || nb > 2147483647))
	{
		return (0);
	}
	*nbr = (int)nb;
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	int i;
	i = atoi_strict("--1", &i);
	printf("%i\n", i);
	i = atoi_strict("+-1", &i);
	printf("%i\n", i);
	i = atoi_strict("1+2", &i);
	printf("%i\n", i);
	i = atoi_strict("2147483648", &i);
	printf("%i\n", i);
	i = atoi_strict("-2147483649", &i);
	printf("%i\n", i);
	i = atoi_strict(" 1", &i);
	printf("%i\n", i);
	i = atoi_strict("1 ", &i);
	printf("%i\n", i);
	return (0);
}
	*/
