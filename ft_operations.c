/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:34:43 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 15:38:27 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_t(t_stack *stack, size_t index_f, size_t index_s)
{
	int		buf;

	buf = stack->num[index_f];
	stack->num[index_f] = stack->num[index_s];
	stack->num[index_s] = buf;
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

void	ft_rot_both(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd)
{
	if (!arg)
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
