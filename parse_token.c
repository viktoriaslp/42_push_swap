#include "push_swap.h"

void	ft_free_mat(char **token)
{
    int i;

    i = 0;
	while (token[i])
	{
		free(token[i]);
        i++;
	}
	free(token);
	return ;
}

int	atoi_strict(const char *nptr, int *nbr)
{
	int		i;
	long	nb;

	nb = 0;
	i = 0;
	if ((nptr[0] == '-' || nptr[0] == '+') && (nptr[1] >= '0' && nptr[1] <= '9'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[0] == '-')
		nb *= -1;
	if ((nptr[i] != '\0' || nptr[0] == '\0') || (nb < -2147483648 || nb > 2147483647))
	{
		return (0);
	}
	*nbr = (int)nb;
	return (1);
}

int is_unique(t_stack *lst, int val)
{
    while (lst != NULL)
    {
        if (lst->value == val)
            return (0);
        lst = lst->next;
    }
    if (lst == NULL)
        return (1);
}
void    ft_error(char **matrix, t_stack **list_a)
{
    if (matrix)
        free_mat(matrix);
    if (list_a)
        free_list(list_a);
    write (2, "Error\n", 6);
    exit (1);
}
void    create_stack_a(char **argv, int count, t_stack **a)
{
    int     i;
    int     j;
    char    **token; 
    int     value;

    i = 0;
    while(i < count) 
    {
        token = ft_split(argv[i], " ");
        if (!token)
            ft_error(token, a);
        j = 0;
        while(token[j])
        {
            if(atoi_strict(token[j], &value) == 1 && is_unique(*a, value) == 1)
                list_add_back(a, ft_lstnew(value));
            else 
                ft_error(token, a);
            j++;
        }
        free_mat(token);
        i++;
    }
    return ;
}
