/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:12:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:28:16 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define B1 b->num[b->index - 1]
#define B2 b->num[b->index - 2]
#define B3 b->num[b->index - 3]
#define A1 a->num[a->index - 1]
#define A2 a->num[a->index - 2]
#define A3 a->num[a->index - 3]

static void		ft_sortmax_a(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (a->srt_i == 0)
		ft_rotate_stack(a, b, 1, cmnd);
	else
	{
		ft_swp(a, b, 0, cmnd);
		ft_push(a, b, 1, cmnd);
	}
	ft_sort_two(a, b, arg, cmnd);
	if (a->srt_i > 0)
	{
		ft_push(a, b, 0, cmnd);
		ft_sort_two(a, b, arg, cmnd);
	}
}

void			ft_sort3a(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (a->index - a->srt_i > 2)
	{
		if (MAX(A1, A2, A3))
			ft_sortmax_a(a, b, arg, cmnd);
		else if (MAX(A2, A1, A3))
		{
			ft_swp(a, b, 0, cmnd);
			ft_sort_small(a, b, arg, cmnd);
		}
		else
			ft_swp(a, b, 0, cmnd);
	}
	else if (a->index - a->srt_i > 1)
		ft_sort_two(a, b, arg, cmnd);
	else
		return ;
}

void			ft_sort3b(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (b->index - b->srt_i > 2)
	{
		if (MAX(B1, B2, B3))
		{
			ft_push(a, b, 0, cmnd);
			ft_sort_two(a, b, arg, cmnd);
		}
		else if (MIN(B1, B2, B3) || MIN(B2, B1, B3))
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
	return ;
}

void			ft_sort_two(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (arg == 'a')
	{
		if (A1 > A2)
			ft_swp(a, b, 0, cmnd);
		else
			return ;
	}
	else
	{
		if (B1 > B2)
			return ;
		else
			ft_swp(a, b, 1, cmnd);
	}
}

void			ft_sort_small(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	if (arg == 'a')
	{
		if (ft_check_sort(a, a->srt_i)
			&& ((a->index - a->srt_i > 1) || (a->srt_i == a->index)))
			return ;
		ft_sort3a(a, b, arg, cmnd);
	}
	else
	{
		if (ft_check_bsort(b, b->srt_i) && ((b->index - b->srt_i > 1)
			|| (b->srt_i == b->index)))
			return ;
		ft_sort3b(a, b, arg, cmnd);
	}
}
