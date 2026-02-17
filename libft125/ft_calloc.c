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

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloc;

	memalloc = (void *) malloc(nmemb * size);
	if (!memalloc)
		return (NULL);
	ft_bzero(memalloc, (nmemb * size));
	return (memalloc);
}
