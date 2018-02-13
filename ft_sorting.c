/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:12:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/13 19:08:59 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_qsort(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	int		pivot;

	if (arg == 'a')
	{
		pivot = ft_get_pivot(a);
		while (!(a->num[a->index - 1] == pivot && ft_check_lower_nums(a, pivot, 'a'))
				&& a->index > 2 + a->srt_i)
		{
			if (a->num[a->index - 1] < pivot)
				ft_push(a, b, 1, cmnd);
			else
				ft_rotate_stack(a, b, 1, cmnd);
		}
		if (a->index - a->srt_i > 3)
		{
			ft_push(a, b, 1, cmnd);
			ft_qsort(a, b, 'a', cmnd); 
		}
		if (a->index - a->srt_i <= 3 && a->index - a->srt_i > 1) ///  плохое условие выхода!!
		{
			ft_sort_small(a, b, 'a', cmnd);
			ft_qsort(a, b, 'b', cmnd); 
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
				ft_push(a, b, 0, cmnd);
			else
				ft_rotate_stack(a, b, 2, cmnd);
		}
		if (b->index - b->srt_i > 3)
		{
			ft_push(a, b, 0, cmnd);
			ft_qsort(a, b, 'b', cmnd); 
		}
		if (b->index - b->srt_i <= 3 && b->index - b->srt_i > 1)
		{
			ft_sort_small(a, b, 'b', cmnd);
			ft_qsort(a, b, 'a', cmnd); 
		}
		else
			return ;	
	}
}


void	ft_sort_small(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
		if (arg == 'a' && !(ft_check_sort(a, a->srt_i - 1)) && a->index - a->srt_i > 2)
		{
			if (a->num[a->index - 1] > a->num[a->index - 2] &&
				a->num[a->index - 1] > a->num[a->index - 3])
			{
				ft_rotate_stack(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
			}
			else if (a->num[a->index - 1] < a->num[a->index - 2] &&
				a->num[a->index - 1] < a->num[a->index - 3])
			{
				ft_push(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_push(a, b, 0, cmnd);
			}
			else
			{
				ft_swp(a, b, 0, cmnd);
				ft_sort_small(a, b, arg, cmnd);
			}
			a->srt_i += 3;
		}
		else if (arg == 'b' && !(ft_check_bsort(b, b->srt_i - 1))&& b->index - b->srt_i > 2 ) 
		{
			if (b->num[b->index - 1] > b->num[b->index - 2] &&
				b->num[b->index - 1] > b->num[b->index - 3])
			{
				ft_push(a, b, 0, cmnd);
				ft_sort_two(a, b, arg, cmnd);
			}
			else if (b->num[b->index - 1] < b->num[b->index - 2] &&
				b->num[b->index - 1] < b->num[b->index - 2])
			{
				ft_rotate_stack(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
			}
			else
			{
				ft_swp(a, b, 0, cmnd);
				ft_sort_small(a, b, arg, cmnd);
			}
			b->srt_i += 3;
		}
		else if (a->index - a->srt_i > 1 || b->index - b->srt_i > 1) 
	{
		if (arg == 'a')
		{
			ft_sort_two(a, b, arg, cmnd);
			a->srt_i += 2;
		}
		else
		{
			ft_sort_two(a, b, arg, cmnd);
			b->srt_i += 2;	
		}
	}
	else
		return ;
}


void	ft_sort_two(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (arg == 'a')
	{
		if (a->num[a->index - 1] > a->num[a->index - 2])
			ft_swp(a, b, 0, cmnd);
		else
			return ;
	}
	else
	{
		if (b->num[b->index - 1] > b->num[b->index - 2])
			return ;
		else
			ft_swp(a, b, 1, cmnd);
	}
}

int		ft_get_pivot(t_stack *stack)
{
	int		i;
	int		sum;
	int		dif;
	int		pivot;

	i = stack->srt_i;
	sum = 0;
	while (i < stack->index)
	{
		sum += stack->num[i];
		i++;
	}
	sum = sum / i + 1;
	i--;
	dif = sum;
	while (i >= 0)
	{
		if (ABS(stack->num[i] - sum) < dif)
		{
			dif = ABS(stack->num[i] - sum);
			pivot = stack->num[i];
			if (dif == 0)
				return (pivot);
		}
		i--;
	}
	return (pivot);
}
