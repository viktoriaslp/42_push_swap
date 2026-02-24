#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

// pos: current position in stack; 
// target_pos: if in stackB the target position in A
// cost_a/b: cost to get this element to yhe top of a/b.
typedef struct s_stack
{
	int			value;
    int         index;
    int         pos;
    int         target_pos;
    int         cost_a;
    int         cost_b;
	struct s_stack	*next;
}	t_stack;

// Parsing input func.
void    create_stack_a(char **argv, int count, t_stack **a);
int     atoi_strict(const char *nptr, int *nbr);
int     is_unique(t_stack *lst, int val);
void    ft_error(char **matrix, t_stack **list_a);
void    ft_free_mat(char **token);

// List func
t_stack *ft_lstnew(int value);
int     ft_lstsize(t_stack *lst); // No se si se usa?
t_stack *ft_lstlast(t_stack *lst);
void    lst_add_back(t_stack **lst, t_stack *new);
void    free_list(t_stack **lst);

// Operations
void    swap(t_stack **list);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    push(t_stack **frst, t_stack **scnd);
void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);
void    rotate(t_stack **list);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    reverse(t_stack **list);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

// Algorithm/Sort Checklist
int     is_sorted(t_stack *list);
void    end_clean(t_stack **list_a, t_stack **list_b);
void    sort_three(t_stack **list);


#endif