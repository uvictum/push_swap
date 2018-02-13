/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:34:43 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/13 14:43:38 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void 	ft_swap_t(t_stack *stack, size_t index_f, size_t index_s)
{
	int		buf;

	buf = stack->num[index_f];
	stack->num[index_f] = stack->num[index_s];
	stack->num[index_s] = buf;
}

void	ft_swp(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd)
{
	if ((arg == 0 || arg == 2) && stack_a->index > 1)
	{
		ft_swap_t(stack_a, stack_a->index - 1, stack_a->index - 2);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("sa\n", 3));
	}
	if (arg > 0 && stack_b->index > 1)
	{
		ft_swap_t(stack_b, stack_b->index - 1, stack_b->index - 2);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("sb\n", 3));
	}
}
void	ft_push(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd)
{
	if (!arg && stack_b->index > 0)
	{
		stack_b->index--;
		stack_a->num[stack_a->index] = stack_b->num[stack_b->index];
		stack_b->num[stack_b->index] = 0;
		stack_a->index++;
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("pa\n", 3));
	}
	else if (arg && stack_a->index > 0)
	{
		stack_a->index--;
		stack_b->num[stack_b->index] = stack_a->num[stack_a->index];
		stack_a->num[stack_a->index] = 0;
		stack_b->index++;
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("pb\n", 3));
	}
}

void	ft_rot_u(t_stack *stack)
{
	int		i;

	i = stack->index - 1;
	while (i > 0)
	{
		ft_swap_t(stack, i, i - 1);
		i--;
	}
}

void	ft_rot_d(t_stack *stack)
{
	int		i;
	
	i = 0;
	while (i < stack->index - 1)
	{
		ft_swap_t(stack, i, i + 1);
		i++;
	}
}

void	ft_rotate_stack(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd)
{
	if (arg == 1 && stack_a->index > 1)
	{
		ft_rot_u(stack_a);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("ra\n", 3));
	}
	else if (arg == 2 && stack_b->index > 1)
	{
		ft_rot_u(stack_b);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("rb\n", 3));
	}
	else if (arg == -1 && stack_a->index > 1)
	{
		ft_rot_d(stack_a);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("rra\n", 4));
	}
	else if (arg == -2 && stack_b->index > 1)
	{
		ft_rot_d(stack_b);
		*cmnd = ft_lstadd_end(*cmnd, ft_lstnew("rrb\n", 4));
	}
}

void	ft_rot_both(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd)
{
	if (arg)
	{
		ft_rotate_stack(stack_a, stack_b, 1, cmnd);
		ft_rotate_stack(stack_a, stack_b, 2, cmnd);
	}
	else
	{
		ft_rotate_stack(stack_a, stack_b, -1, cmnd);
		ft_rotate_stack(stack_a, stack_b, -2, cmnd);
	}
}
