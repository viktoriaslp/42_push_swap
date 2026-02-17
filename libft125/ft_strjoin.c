/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:09:04 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/17 15:19:28 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	lens1;
	size_t	len;

	lens1 = ft_strlen(s1);
	len = lens1 + ft_strlen(s2) + 1;
	newstr = (char *) malloc(len * sizeof(char));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, lens1 + 1);
	ft_strlcat(newstr, s2, len);
	return (newstr);
}
