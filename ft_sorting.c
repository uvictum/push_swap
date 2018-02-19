/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:12:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/19 18:34:21 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (arg == 'a')
	{	
		if (ft_check_sort(a, a->srt_i - 1) && (a->index - (a->srt_i + (a->srt_i > 0 ? 1 : 0)) > 1 || (a->srt_i == a->index - 1)))
		{
			ft_last_srtd(a, b);
			return ;
		}	
		if	(a->index - (a->srt_i + (a->srt_i > 0 ? 1 : 0)) > 2)
		{
			if (MAX(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
			{
				if (a->srt_i == 0)
				{	
					ft_rotate_stack(a, b, 1, cmnd);
					ft_sort_two(a, b, arg, cmnd);
				}
				else
					ft_simple_sort(a, b, arg, cmnd);
			}
			else if (MIN(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
			{
				ft_push(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_push(a, b, 0, cmnd);
				ft_last_srtd(a, b);
			}
			else
			{
				ft_swp(a, b, 0, cmnd);
				ft_sort_small(a, b, arg, cmnd);
			}
			ft_last_srtd(a, b);
		}
		else if (a->index - (a->srt_i + (a->srt_i > 0 ? 1 : 0)) > 1)
		{
			ft_sort_two(a, b, arg, cmnd);
			ft_last_srtd(a, b);
		}
		else
		{
			ft_push(a, b, 1, cmnd);
			ft_last_srtd(a, b);
			return ;
		}
	}
	else 
	{	
		if (ft_check_bsort(b, b->srt_i - 1) && (b->index - (b->srt_i + (b->srt_i > 0 ? 1 : 0)) > 1 || (b->srt_i == b->index - 1)))
		{
			ft_last_srtd(a, b);
			return ;
		}	
		if	(b->index - (b->srt_i + (b->srt_i > 0 ? 1 : 0)) > 2) 
		{
			if (MAX(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]))
			{
				ft_push(a, b, 0, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_last_srtd(a, b);
			}
			else if (MIN(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]))
			{
				if (b->srt_i == 0)
				{
					ft_rotate_stack(a, b, 2, cmnd);
					ft_sort_two(a, b, arg, cmnd);
				}
				else
					ft_simple_sort(a, b, arg, cmnd);
				ft_last_srtd(a, b);
			}
			else
			{
				ft_swp(a, b, 1, cmnd);
				ft_sort_small(a, b, arg, cmnd);
			}
		}
		else if (b->index - (b->srt_i + (b->srt_i > 0 ? 1 : 0)) > 1 && !ft_check_bsort(b, b->srt_i - 1))
		{
			ft_sort_two(a, b, arg, cmnd);
			ft_last_srtd(a, b);
		}
		else if (b->index - (b->srt_i + (b->srt_i > 0 ? 1 : 0)) == 1)
		{
			ft_push(a, b, 0, cmnd);
			ft_last_srtd(a, b);
			return;
		}
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
	while (s < a->index - a->srt_i)
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
	i = a->num[a->srt_i + ((a->index - a->srt_i)/2)];
	free(a->num);
	free(a);
	return (i);
}

t_stack		*ft_copy_stack(t_stack *a)
{
	t_stack *stack;
	int		i;

	i = 0;
	stack = (t_stack *)ft_memalloc(sizeof(t_stack));
	stack->index = a->index;
	stack->srt_i = a->srt_i;
	stack->num = (int *)ft_memalloc(sizeof(int) * stack->index);
	while (i < a->index)
	{
		stack->num[i] = a->num[i];
		i++;
	}	
	return(stack);
}

void		ft_last_srtd(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	a->srt_i = 0;
	while (i < a->index - 1)
	{
		if (a->num[i] > a->num[i + 1])
		{
			a->srt_i++;
			if (ft_check_lower_nums(a, a->num[i + 1], 'b', 0) && 
				ft_check_lower_nums(b, a->num[i + 1], 'b', 0))
				i++;
			else
			{
				a->srt_i--;
				break ;
			}
		}
		else
			break ;
	}
	i = 0;
	b->srt_i = 0;
	while(i < b->index - 1)
	{
		if (b->num[i] < b->num[i + 1])
		{
			b->srt_i++;
			if (ft_check_lower_nums(b, b->num[i + 1], 'a', 0) && 
				ft_check_lower_nums(a, b->num[i + 1], 'a', 0))
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


void		ft_simple_sort(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	int		j;

	ft_last_srtd(a, b);
	if (arg == 'a')
	{
		j = b->index;
		while (a->index - 1 > a->srt_i)
		{
			if (j < b->index - 1 && b->num[b->index - 1] < b->num[b->index - 2])
				ft_swp(a, b, 1, cmnd);
			ft_push(a, b, 1, cmnd);
		}
		while (j < b->index)
			ft_push(a, b, 0, cmnd);
	}	
	else
	{
		j = a->index;
		while (b->index - 1 > b->srt_i)
		{
			if (j < a->index - 1 && a->num[a->index - 1] > a->num[a->index - 2]) 
				ft_swp(a, b, 0, cmnd);
			ft_push(a, b, 0, cmnd);
		}
		while (j < a->index)
			ft_push(a, b, 1, cmnd);
	}
}

