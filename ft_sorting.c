/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:12:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/15 20:39:34 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_qsort(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	int		pivot;
	
	ft_last_srtd(a, b);
	if (arg == 'a')
	{
		pivot = ft_get_pivot(ft_copy_stack(a));
		//printf("pivot[%c] = %d\n", arg, pivot);
		while (!(a->num[a->index - 1] == pivot && ft_check_lower_nums(a, pivot, 'a', 1))
				&& a->index > 3 + a->srt_i)
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
		pivot = ft_get_pivot(ft_copy_stack(b));
	//	printf("pivot[%c] = %d\n", arg, pivot);
		while (!(b->num[b->index - 1] == pivot && ft_check_lower_nums(b, pivot, 'b', 1))
				&& b->index > 3 + b->srt_i)
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
		if (arg == 'a')
		{	
			if (ft_check_sort(a, a->srt_i - 1))
			{
				a->srt_i += 3;
				return ;
			}	
			if	(a->index - a->srt_i > 2)
			{
				if (MAX(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
				{
					ft_rotate_stack(a, b, 1, cmnd);
					ft_sort_two(a, b, arg, cmnd);
					a->srt_i += 3;
				}
				else if (MIN(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
				{
					ft_push(a, b, 1, cmnd);
					ft_sort_two(a, b, arg, cmnd);
					ft_push(a, b, 0, cmnd);
					a->srt_i += 3;
				}
				else
				{
					ft_swp(a, b, 0, cmnd);
					ft_sort_small(a, b, arg, cmnd);
				}
			}
			else if (a->index - a->srt_i > 1)
			{
				ft_sort_two(a, b, arg, cmnd);
				a->srt_i += 2;
			}
			else
				return ;
		}
		else 
		{	
			if (ft_check_bsort(b, b->srt_i - 1))
			{
				b->srt_i += 3;
				return ;
			}	
			if	(b->index - b->srt_i > 2) 
			{
				if (MAX(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]))
				{
					ft_push(a, b, 0, cmnd);
					ft_sort_two(a, b, arg, cmnd);
					b->srt_i += 3;
				}
				else if (MIN(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]))
				{
					ft_rotate_stack(a, b, 2, cmnd);
					ft_sort_two(a, b, arg, cmnd);
					b->srt_i += 3;
				}
				else
				{
					ft_swp(a, b, 1, cmnd);
					ft_sort_small(a, b, arg, cmnd);
				}
			}
			else if (b->index - b->srt_i > 1 && !ft_check_bsort(b, b->srt_i - 1))
			{
				ft_sort_two(a, b, arg, cmnd);
				b->srt_i += 2;	
			}
			else
				return;
		}
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

int		ft_get_pivot(t_stack *a)
{
	int			buf;
	int			i;
	int			s;

	s = 0;
	while (s < a->index)
	{	
		i = a->srt_i;
		while (i < a->index - 1 - s)
		{
			if (a->num[i] < a->num[i + 1])
			{
				buf = a->num[i];
				a->num[i] = a->num[i + 1];
				a->num[i + 1] = buf;
			}
			i++;
		}
		s++;
	}
	i = a->num[a->index/2];
	free(a->num);
	free(a);
	return (i);
}

t_stack		*ft_copy_stack(t_stack *a)
{
	t_stack *stack;
	int		i;
	int		j;

	j = 0;
	i = a->srt_i;
	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack->index = a->index - a->srt_i;
	stack->num = (int *)ft_memalloc(sizeof(int) * stack->index);
	while (i < a->index && j < stack->index)
	{
		stack->num[j] = a->num[i];
		i++;
		j++;
	}	
	return(stack);
}

void		ft_last_srtd(t_stack *a, t_stack *b)
{
	int		i;

	i = a->srt_i;
	while (i < a->index - 1)
	{
		if (a->num[i] > a->num[i + 1])
		{
			a->srt_i++;
			if (ft_check_lower_nums(a, a->num[i + 1], 'b', 0))
				i++;
			else
			{
				a->srt_i--;
				return ;
			}
		}
		else
			return ;
	}
	i = b->srt_i;
	while(i < b->index - 1)
	{
		if (b->num[i] < b->num[i + 1])
		{
			b->srt_i++;
			if (ft_check_lower_nums(b, b->num[i + i], 'a', 0))
				i++;
			else
			{
				b->srt_i--;
				return;
			}
		}
		else
			return ;
	}
}

	
