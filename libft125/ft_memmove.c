/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:42:44 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/24 10:44:02 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*strd;
	unsigned char	*strs;

	strd = (unsigned char *) dest;
	strs = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	if (strd > strs)
	{
		while (n > 0)
		{
			n--;
			strd[n] = strs[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
