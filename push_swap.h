#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h> // only for testing purposes, remove when finished.

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
    int         total_cost;
	struct s_stack	*next;
}	t_stack;

// Parsing input func. parse_token.c & parse_util.split.c
void    create_stack_a(char **argv, int count, t_stack **a);
int     atoi_strict(const char *nptr, int *nbr);
int     is_unique(t_stack *lst, int val);
void    ft_error(char **matrix, t_stack **list_a);
void    ft_free_mat(char **token);
char	**ft_split(char const *s, char c);

// List func
t_stack *ft_lstnew(int value);
int     ft_lstsize(t_stack *lst); // No se si se usa?
t_stack *ft_lstlast(t_stack *lst);
void    lst_add_back(t_stack **lst, t_stack *new);

// Lists memory handleling
void	*ft_calloc(size_t nmemb, size_t size);
void    free_list(t_stack **lst);
void    end_clean(t_stack **list_a, t_stack **list_b);

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

// Algorithm/Sort Checklist
int     is_sorted(t_stack *list);
void    sort_three(t_stack **list);

void    set_index(t_stack *a); // mover junto con lowest_cost y do_rotatoins y final sort
void    final_sort(t_stack **a, int size_a);

void    push_swap(t_stack **orig_a, t_stack **orig_b, int size_a);
void    do_rot(t_stack **a, t_stack **b, int rot_a, int rot_b);
void	rot_one_list(t_stack **list, void (*op)(t_stack **), int n);

// Setting node info
void    set_cur_pos(t_stack *head);
void    set_tar_pos(t_stack *a, t_stack *b);
void    cost_b(t_stack *list, int size);
void    cost_a(t_stack *list, int size);
void    set_total_cost(t_stack *b, int size_a, int size_b);


t_stack *lowest_cost(t_stack *b);
t_stack *find_lowest(t_stack *a);
int     fc_abs(int x);
int     fc_max(int x, int y);
int     fc_min(int x, int y);




#endif