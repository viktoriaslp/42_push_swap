/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:31:55 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/26 12:59:28 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nb;
	char		c;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd((nb / 10), fd);
	c = (nb % 10) + '0';
	ft_putchar_fd((c), fd);
	return ;
}

/*
int main(void)
{
	ft_putnbr_fd(123, 1);
        ft_putnbr_fd(-345, 1);
        ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
