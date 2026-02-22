#include "push_swap.h"

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

t_stack *create_stack_a(char **argv, int count)
{

    // 1. Tokenizar
    // 2. Parse tokens
    // 3. Crear stack
    int     i;
    int     j;
    char    **token;
    int     value;
    t_stack *stack_a;

    stack_a = NULL;
    i = 0;
    while(argv[i] && i < count)
    {
        token = ft_split(argv[i], " "); //Protejer split de NULL??
        j = 0;
        while(token[j])
        {
            if(atoi_strict(token[j], &value) == 1 && is_unique(stack_a, value) == 1)
            {
                // add to the stack list.
                // use calloc to create a node so the values are init to 0.
            }
            else 
            {
                write (2, "Error\n", 6);
                return (NULL);
            }
            j++;
        }
        free(token);
        i++;
    }
    return (stack_a);
}
        // Comprobar que argv es un int
        // Comprobar que argv no super INT_MIN o INT_MAX
        // Comprobar que no hay duplicados

        // use lstadd_back (first parameter stay as head of list)
        // al primer error encontrado imprimimos error y devolvemos NULL.