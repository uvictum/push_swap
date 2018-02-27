/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:12:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/27 19:30:39 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (arg == 'a')
	{	
		if (ft_check_sort(a, a->srt_i)
			&& ((a->index - a->srt_i > 1) || (a->srt_i == a->index)))
				return ;
	
/*void ft_sort3a(t_stack *a, t_stack *b, cmnd);
{
	av = get_avrg(a);
	while (a->index - a->srt_i > 2)
	{
		if (a->num[a->index - 1] >= av)
		{
			ft_rotate_stack(a, b, 1, cmnd);
			if (a->srt_i > 0)
				i++;
		}
		else
			ft_push(a, b, 0, cmnd);
		while (i > 0)
		{
			ft_rotate_stack(a, b, -1, cmnd);
			i--;
		}
	}
	ft_sort_two(a, b, 'a', cmnd);
}*/


		if	(a->index - a->srt_i > 2)
		{
			if (MAX(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
			{
				ft_rotate_stack(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_push(a, b, 1, cmnd);
				if (a->srt_i > 0)
				{
					ft_rotate_stack(a, b, -1, cmnd);
					ft_sort_two(a, b, arg, cmnd);
				}
				ft_push(a, b, 0, cmnd);
			}
			else if (MIN(a->num[a->index - 1], a->num[a->index - 2], a->num[a->index - 3]))
			{
				ft_rotate_stack(a, b, 1, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_rotate_stack(a, b, -1, cmnd);
			}
			else
			{
				ft_swp(a, b, 0, cmnd);
				ft_sort_small(a, b, arg, cmnd);
			}
		}
		else if (a->index - a->srt_i > 1)
			ft_sort_two(a, b, arg, cmnd);
		else
			return ;
	}
	else 
	{	
		if (ft_check_bsort(b, b->srt_i) && ((b->index - b->srt_i > 1) 
			|| (b->srt_i == b->index)))
			return ;
	//	ft_sort3b(a, b, cmnd);



		if	(b->index - b->srt_i > 2) 
		{
			if (MAX(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]))
			{
				ft_push(a, b, 0, cmnd);
				ft_sort_two(a, b, arg, cmnd);
			}
			else if (MIN(b->num[b->index - 1], b->num[b->index - 2], b->num[b->index - 3]) 
					|| MIN(b->num[b->index - 2], b->num[b->index - 1], b->num[b->index - 3]))
			{
				ft_rotate_stack(a, b, 2, cmnd);
				ft_sort_two(a, b, arg, cmnd);
				ft_push(a, b, 0, cmnd);
				if (b->srt_i > 0)
					ft_rotate_stack(a, b, -2, cmnd);
				ft_sort_two(a, b, arg, cmnd);
			}
			else
				ft_swp(a, b, 1, cmnd);
		}
		else if (b->index - b->srt_i > 1 && !ft_check_bsort(b, b->srt_i))
			ft_sort_two(a, b, arg, cmnd);
		else if (b->index - b->srt_i == 1)
			ft_push(a, b, 0, cmnd);
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
	s = (a->srt_i + ((a->index - a->srt_i)/2));
	i = a->num[s + ((a->index - a->srt_i) % 2 == 0 ? - 1 : 0)]; //убрать тернарную операци/
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

void		ft_simple_sort(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	int		j;

	if (arg == 'a')
	{
		j = b->index;
		while (a->index  > a->srt_i)
		{
			ft_push(a, b, 1, cmnd);
			if (j < b->index - 1 && b->num[b->index - 1] < b->num[b->index - 2])
				ft_swp(a, b, 1, cmnd);
		}
		while (j < b->index)
			ft_push(a, b, 0, cmnd);
	}	
	else
	{
		j = a->index;
		while (b->index > b->srt_i)
		{
			ft_push(a, b, 0, cmnd);
			if (j < a->index - 1 && a->num[a->index - 1] > a->num[a->index - 2]) 
				ft_swp(a, b, 0, cmnd);
		}
		while (j < a->index)
			ft_push(a, b, 1, cmnd);
	}
}

