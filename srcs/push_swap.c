/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gartanis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 16:05:05 by gartanis          #+#    #+#             */
/*   Updated: 2020/06/23 16:05:50 by gartanis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	mini_sort(t_linklist *lst, t_stack *stack)
{
	if (!issort(lst))
	{
		if (lst->head->data > lst->head->next->data)
			swap(lst, stack);
		else if (lst->head->next->data > lst->tail->data)
			revrotate(lst, stack);
		else
			rotate(lst, stack);
		mini_sort(lst, stack);
	}
}

void	small_sort(t_linklist *lst, t_stack *stack)
{
	if (!issort(list))
	{
		if (list->size > 2 && list->head->data > list->head->next->data)
		{
			if (list->head->data > list->head->next->next->data)
				rotate(list, stack);
			else
				swap(list, stack);
		}
		else
			revrotate(list, stack);
		small_sort(list, stack);
	}
}

void	quick_sort(t_linklist *src, t_linklist *dst, t_stack *stack)
{
	stack->div = 2;
	if (!issort(src))
	{
		if (src->size > 3)
			split_stack(src, dst, stack);
		else
			small_sort(src, stack);
		quick_sort(src, dst, stack);
	}
	// else if (dst->size > 0)
	// {
		// merger_stack(src, dst, stack);
		// quick_sort(src, dst, stack);
	// }
}

void	sort_stack(t_stack *stack)
{
	if (stack->stack[0]->size <= 3)
		small_sort(stack->stack[0], stack);
	else if (stack->stack[0]->size <= 6)
		small_sort(stack->stack[0], stack);
	else
		quick_sort(stack->stack[0], stack->stack[1], stack);
}

int		main(int ac, char *av[])
{
	t_stack		stack;
	int			ret;

	ret = 0;
	stack.prg = *av;
	stack.print = 1;
	if (ac < 2)
		return (print_error(&stack, NOARG));
	av += 1;
	if ((ret = init_stack(&stack, av, ac)))
		return (print_error(&stack, ret));
	if (stack.opt & OPT_F)
		stack.fd = open(OUTPUT_PS, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	sort_stack(&stack);
	free_stack(&stack);
	return (ret);
}

// 1
// 2
// 3
// 4
// 5
// 6