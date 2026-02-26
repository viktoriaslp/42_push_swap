/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:58:46 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:01:27 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_letter_count(char const *s, char c, size_t *size)
{
	char	*temp;
	size_t	l;

	while (*s == c)
		s++;
	if (*s == '\0')
	{
		*size = 0;
		return (NULL);
	}
	temp = (char *) s;
	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	*size = l;
	return (temp);
}

static void	*ft_free_matrix(char **words, size_t i)
{
	while (i > 0)
	{
		i--;
		free(words[i]);
	}
	free(words);
	return (NULL);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**words;
	size_t	size;
	char	*cursor;

	word_count = ft_word_count(s, c);
	words = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	cursor = (char *) s;
	i = 0;
	while (i < word_count)
	{
		cursor = ft_letter_count(cursor, c, &size);
		words[i] = (char *) malloc((size + 1) * sizeof(char));
		if (!words[i])
			return (ft_free_matrix(words, i));
		ft_strlcpy(words[i], cursor, size + 1);
		cursor = cursor + size;
		i++;
	}
	words[i] = NULL;
	return (words);
}
