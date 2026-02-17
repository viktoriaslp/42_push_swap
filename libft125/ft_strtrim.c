/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:20:35 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/24 14:57:29 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	if (end == 0)
		return (ft_strdup(""));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]) != NULL)
		start++;
	end--;
	while (end > start && ft_strchr(set, s1[end]) != NULL)
		end--;
	len = end - start + 2;
	strtrim = (char *) malloc((len) * sizeof(char));
	if (!strtrim)
		return (NULL);
	ft_strlcpy(strtrim, &s1[start], len);
	return (strtrim);
}
