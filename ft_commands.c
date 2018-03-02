/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:39:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:27:09 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_commands(t_stack *a, t_stack *b, t_list *cmnd)
{
	{
		while (cmnd)
		{
			write(1, cmnd->content, cmnd->content_size);
			cmnd = cmnd->next;
		}
	}
	ft_lstdel(&cmnd, &ft_dellst);
	ft_del_stack(a);
	ft_del_stack(b);
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

void	ft_rotate_stack(t_stack *stack_a, t_stack *stack_b,
		int arg, t_list **cmnd)
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
