/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:27:23 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/24 12:07:37 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*strd;
	unsigned char	*strs;
	size_t			i;

	strd = (unsigned char *) dest;
	strs = (unsigned char *) src;
	if (!src && !dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		strd[i] = strs[i];
		i++;
	}
	return (dest);
}
