#include "header.h"

t_stack	*stack_new(int num)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	tmp->num = num;
	tmp->next = NULL;
	return (tmp);
}

t_stack	*stack_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stack_append(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = stack_last(*lst);
	tmp->next = new;
}

t_stack	*stack_arr(char **ptr)
{
	t_stack	*lst;
	int		i;

	i = 0;
	lst = NULL;
	while (ptr[i])
	{
		stack_append(&lst, stack_new(atoi(ptr[i])));
		i++;
	}
	return (lst);
}

void	ft_lstprint(t_stack *lst, char *name)
{
	int	size;

	size = 0;
	printf("%s : ", name);
	while (lst)
	{
		printf("%d", lst->num);
		if (lst->next)
			printf("->");
		lst = lst->next;
		size++;
	}
	printf("\n");
}
