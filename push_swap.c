/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:03:35 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 19:33:50 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack 	*a;
	t_stack		*b;
	t_list		*cmnd
	int			pivot;

	a = ft_readstack_a(argv, argc, flag);
	b = ft_alloc_stack(argc);	
	ft_qsort(a, b, 'a', cmnd);
	ft_back_b(a, b);
	ft_optimize_commands(cmnd);
	ft_print_commands(a, b, cmnd);
}

void	ft_qsort(t_stack *a, t_stack *b, char arg)
{
	if (arg == 'a')
	{
		pivot = ft_get_pivot(a);
		while (!(a->num[a->index - 1] == pivot && ft_check_lower_nums(a, pivot, 'a'))// для выхода отдать 1
				&& a->index > 2 + a->srt_i)
		{
			if (a->num[a->index - 1] < pivot)
				ft_push(a, b, 1);
			else
				ft_rotate_stack(a);
		}
		if (a->index > 3 + a->srt_i)
		{
			ft_push(a, b, 1);
			ft_qsort(a, b, 'a'); 
		}
		if (a->index <= 3 + a->srt_i)
		{
			ft_sort_small(a, 'a');
			ft_qsort(a, b, 'b'); 
		}
		else
			return ;	
	}
	else
	{
		pivot = ft_get_pivot(b);
		while (!(b->num[b->index - 1] == pivot && ft_check_lower_nums(b, pivot, 'b'))
				&& b->index > 2 + b->srt_i)
		{
			if (b->num[b->index - 1] > pivot)
				ft_push(a, b, 0);
			else
				ft_rotate_stack(b);
		}
		if (b->index > 3 + b->srt_i)
		{
			ft_push(a, b, 0);
			ft_qsort(a, b, 'b'); 
		}
		if (b->index <= 3 + b->srt_i)
		{
			ft_sort_small(b, 'b');
			ft_qsort(a, b, 'a'); 
		}
		else
			return ;	
	}
}

int		ft_check_lower_sum(t_stack *a, int pivot, char stack)
{
	int		i;

	i = 0;
	if (stack == 'a')
	{
		while(i < a->index - 1)
		{
			if (a[i] < pivot)
				return (0);
			i++;
		}
		return(1);
	}
	else
		while (i < a->index - 1)
		{
			if (a[i] > pivot)
			   return (0);
			i++;
		}	
		return (1);
	}
}

int		ft_get_pivot(t_stack *stack)
{
	int		i;
	int		sum;
	int		dif;

	i = 0;
	pivot = 0;
	while (i < stack->index)
	{
		sum += stack->num[i];
		i++;
	}
	sum = sum / i;
	i--;
	dif = sum;
	while (i > 0)
	{
		if (ABS(stack->num[i] - sum) < dif)
		{
			dif = ABS(stack->num[i] - sum);
			pivot = stack->num[i];
		}
		i--;
	}
	return (pivot);
}

void	ft_sort_small(t_stack *stack, char arg)
{
	if (stack->index - stack->srt_i > 2)
	{
		if (arg == 'a' && !(ft_check_sort(stack, stack->index - stack->srt_i)))
		{
			if (stack->num[stack->index - 1] > stack->num[stack->index - 2] &&
				stack->num[stack->index - 1] > stack->num[stack->index - 3])
			{
				ft_rot_u(stack);
				ft_sort_two(stack, arg);
			}
			else if (stack->num[stack->index - 1] < stack->num[stack->index - 2] &&
				stack->num[stack->index - 1] < stack->num[stack->index - 3])
			{
				ft_push(stack, 1);
				ft_sort_two(stack, arg);
			}
			else
			{
				ft_swap_t(stack, stack->index - 1, stack->index - 2);
				ft_sort_small(stack, arg);
			}
		}
		else if (arg == 'b' && !(ft_check_bsort(stack, stack->index - stack->srt_i)) 
			&& stack->index - stack->srt_i > 2)
		{
			if (stack->num[stack->index - 1] > stack->num[stack->index - 2] &&
				stack->num[stack->index - 1] > stack->num[stack->index - 3])
			{
				ft_push(stack, 0);
				ft_sort_two(stack, arg);
			}
			else if (stack->num[stack->index - 1] < stack->num[stack->index - 2] &&
				stack->num[stack->index - 1] < stack->num[stack->index - 2])
			{
				ft_rot_u(stack);
				ft_sort_two(stack, arg);
			}
			else
			{
				ft_swap_t(stack, stack->index - 1, stack->index - 2);
				ft_sort_small(stack, arg);
			}
		}
		else if (stack->index - stack->srt_i > 1)
			ft_sort_two(stack, arg);
		else
			return ;

void	ft_sort_two(t_stack *stack, char arg)
{
	if (arg == 'a')
	{
		if (stack->num[stack->index - 1] > stack->num[stack->index - 2])
			ft_swap_t(stack, stack->index - 1, stack->index - 2);
		else
			return ;
	}
	else
	{
		if (stack->num[stack->index - 1] > stack->num[stack->index - 2])
			return ;
		else
			ft_swap_t(stack, stack->index - 1, stack->index - 2);
	}
}


