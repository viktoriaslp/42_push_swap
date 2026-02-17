/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:19:26 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/25 17:21:01 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len(long int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_create_nbr(char *nbr, long int nb, int len)
{
	while (len > 0)
	{
		nbr[len - 1] = (nb % 10) + '0';
		len--;
		nb = nb / 10;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char		*nbr;
	char		sign;
	int			len;
	long int	nb;

	len = 0;
	sign = ' ';
	nb = n;
	if (nb < 0)
	{
		len++;
		sign = '-';
		nb *= -1;
	}
	if (nb == 0)
		len++;
	len = len + ft_nbr_len(nb);
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	nbr = ft_create_nbr(nbr, nb, len);
	if (sign == '-')
		nbr[0] = sign;
	return (nbr);
}

/*
#include <stdio.h>

int	main()
{
	char	*nbr;

	nbr = ft_itoa(0);
	printf("%s\n", nbr);
	return (0);
}*/
