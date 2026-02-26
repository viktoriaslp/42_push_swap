/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vslyunko <vslyunko@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:52:05 by vslyunko          #+#    #+#             */
/*   Updated: 2026/02/26 15:00:28 by vslyunko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(t_stack *lst, int val)
{
	while (lst != NULL)
	{
		if (lst->value == val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_free_mat(char **token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		free(token[i]);
		i++;
	}
	free(token);
	return ;
}

void	ft_error(char **matrix, t_stack **list_a)
{
	if (matrix)
		ft_free_mat(matrix);
	if (list_a)
		free_list(list_a);
	write (2, "Error\n", 6);
	exit (1);
}

int	atoi_strict(const char *nptr, int *nbr)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if ((nptr[0] == '-' || nptr[0] == '+')
		&& (nptr[1] >= '0' && nptr[1] <= '9'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[0] == '-')
		nb *= -1;
	if ((nptr[i] != '\0' || nptr[0] == '\0')
		|| (nb < -2147483648 || nb > 2147483647))
	{
		return (0);
	}
	*nbr = (int)nb;
	return (1);
}

void	create_stack_a(char **argv, int count, t_stack **a)
{
	char	**token;
	int		i;
	int		j;
	int		value;

	i = 0;
	while (i < count)
	{
		token = ft_split(argv[i], ' ');
		if (!token || argv[i][0] == '\0')
			ft_error(token, a);
		j = 0;
		while (token[j])
		{
			if (atoi_strict(token[j], &value) == 1 && is_unique(*a, value) == 1)
				lst_add_back(a, ft_lstnew(value));
			else
				ft_error(token, a);
			j++;
		}
		ft_free_mat(token);
		i++;
	}
	return ;
}
