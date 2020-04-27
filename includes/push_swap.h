#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "../libft/libft.h"
# include <stdio.h>

# define OUTPUT_PS "OPERATIONS.txt"

/*
** Error message
*/

# define NOARG          (1 << 0)
# define EOVERFLOW      (1 << 1)
# define DUBLICATE      (1 << 2)
# define ARGNOINT       (1 << 3)

# define ERR_M           "\033[31;1merror:\033[00m"
# define NOARG_MS        "\033[39;1mmissing arguments\033[0m"
# define EOVERFLOW_MS    "\033[39;1mvalue too large to be stored in data type\033[0m"
# define DUBLICATE_MS    "\033[39;1mthere are duplicates\033[0m"
# define ARGNOINT_MS     "\033[39;1margument are not integer\033[0m"
# define OK              "\033[32;1mOK\033[00m"
# define KO              "\033[31;1mKO\033[00m"

# define OPT_V (1 << 0)
# define OPT_C (1 << 1)
# define OPT_F (1 << 2)

typedef struct      s_node
{
    struct s_node    *next;
    struct s_node    *prev;
    int             data;
}                   t_node;

typedef struct  s_linklist
{
    t_node      *head;
    t_node      *tail;
    size_t      size;
    char        letter;
}               t_linklist;

typedef struct      s_stack
{
    char            *prg;
    int             div;
    int             opt;
    int             fd;
    int             print;
    t_linklist    *stack[2];
}                   t_stack;


int     init_stack(t_stack *stack, char *av[], int ac);
char    **get_arg(t_stack *stack, int ac, char *av[]);
int     check_stack(char **str);

int     get_median(t_linklist *stack, int div);
int     is_substack(t_node *list, int med);
int     issort(t_linklist *stack);

int     print_error(t_stack stack, int errcode);
void    print_operation(t_stack *stack, const char *str, const char let);

void    sort_stack(t_stack *stack);
void    small_sort(t_linklist *list, t_stack *stack);
void    quick_sort(t_linklist *src, t_linklist *dst, t_stack *stack);
void    merger_stack(t_linklist *src, t_linklist *dst, t_stack *stack);
void    split_stack(t_linklist *src, t_linklist *dst, int med, t_stack *stack);

/*
** operations
*/

void    rotate(t_linklist *list, t_stack *stack);
void    doub_rotate(t_linklist *src, t_linklist *dst, t_stack *stack);
void    revrotate(t_linklist *list, t_stack *stack);
void    doub_revrotate(t_linklist *src, t_linklist *dst, t_stack *stack);
void    swap(t_linklist *list, t_stack *stack);
void    doub_swap(t_linklist *src, t_linklist *dst, t_stack *stack);
void    push(t_linklist *src, t_linklist *dst, t_stack *stack);

#endif