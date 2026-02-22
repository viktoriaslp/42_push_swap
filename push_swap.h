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

#endif