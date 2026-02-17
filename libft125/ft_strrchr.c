/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:20:53 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/17 10:16:35 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	char	*str;
	size_t	i;

	cc = (char) c;
	str = (void *) 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			str = (char *) &s[i];
		i++;
	}
	if (s[i] == cc)
		str = (char *) &s[i];
	return (str);
}
