/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:39:43 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/24 13:04:36 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (s);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloc;

	memalloc = (void *) malloc(nmemb * size);
	if (!memalloc)
		return (NULL);
	ft_memset(memalloc, (nmemb * size));
	return (memalloc);
}
