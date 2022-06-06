#ifndef	HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "./includes/libft/libft.h"

typedef struct s_deneme
{
	int count;
} t_deneme;


typedef struct s_list_min_max
{
	int min;
	int max;
}	t_list_min_max;

typedef struct s_stack
{
	int		num;
	int		index;
	int 	*binary;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move_select
{
	char	*name;
	void	(*f)(t_stack **, t_stack **);
}	t_move_select;



//main push_swap;
void	push_swap(int ac, char **av);
int 	compaire(t_stack **lista, t_stack **listb);
void	coma(t_stack **lista);
void	comb(t_stack **listb);
void 	push_coma(t_stack **lista, t_stack **listb);
int 	ft_cmp(int num1, int num2);
int		binary_of_zero(t_stack *lista, int index);
int		is_sorted(t_stack *lista);
void hard_solve(t_stack **lista, t_stack **listb);
//tab operation
int		tab_avg(t_stack *list);
int		find_min(int *tab);

//operation 
void	swap_a(t_stack **lista, t_stack **listb);
void	swap_b(t_stack **lista, t_stack **listb);
void	swap_ss(t_stack **lista, t_stack **listb);
void	push_a(t_stack **lista, t_stack **listb);
void	push_b(t_stack **lista, t_stack **listb);
void	rotate_a(t_stack **lista, t_stack **listb);
void	rotate_b(t_stack **lista, t_stack **listb);
void	rotate_rr(t_stack **lista, t_stack **listb);
void	rev_rotate_a(t_stack **lista, t_stack **listb);
void	rev_rotate_b(t_stack **lista, t_stack **listb);
void	rev_rotate_rrr(t_stack **lista, t_stack **listb);

//operation handler
void	handler(char *name, t_stack **lista, t_stack **listb);
t_stack	*stack_arr(char **ptr);
void	stack_append(t_stack **lst, t_stack *new);
t_stack	*stack_last(t_stack *lst);
void	stack_add_index(t_stack **list);

//sort algoritm
int 	partition(int *array, int low, int high);
void	quick_sort(int *array, int low, int high);
void	swap(int *a, int *b);

//tab array
int		*list_to_arr(t_stack *list);
int		array_cmp(t_stack *list, int *tab);
int		*arg_to_arr(char **str);

//binary
int		*decimal_to_binary(int n);
int		ft_count_digits_llud(long long value, int base);

//lstprint
void	ft_list_print(t_stack *lst, char *name);
void	ft_list_index_print(t_stack *lst, char *name);
void	ft_list_binary_print(t_stack *lst, char *name);

//list
int		list_size(t_stack *lst);
#endif
