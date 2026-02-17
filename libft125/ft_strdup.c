/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:58:32 by vslyunko          #+#    #+#             */
/*   Updated: 2025/11/17 13:31:38 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*temp;

	len = ft_strlen(s);
	temp = (char *) malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, s, len + 1);
	return (temp);
}
