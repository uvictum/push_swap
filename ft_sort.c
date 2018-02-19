/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:03:02 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/19 18:36:07 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nsort(t_stack *a, t_stack *b, t_list **cmnd)
{
	while (a->srt_i != a->index - 1)
	{
		ft_last_srtd(a, b);
		while (a->index - a->srt_i > 3)
			ft_qsort_a(a, b, cmnd);
		ft_sort_small(a, b ,'a', cmnd);
		while (b->index - (b->srt_i + (b->srt_i > 0 ? 1 : 0)) > 3 && b->index > 0)
			ft_qsort_b(a, b, cmnd);
		ft_sort_small(a, b, 'b', cmnd);
		//ft_print_stack(a, b);
	}
}

void	ft_qsort_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		pivot;
	int		i;

	i = 0;
	pivot = ft_get_pivot(ft_copy_stack(a));
	while (!ft_check_lower_nums(a, pivot, 'a', 0) 
			&& a->index > 3 + a->srt_i)
	{	
		if (a->num[a->index - 1] < pivot)
			ft_push(a, b, 1, cmnd);
		else
		{
			ft_rotate_stack(a, b, 1, cmnd);
			if (a->srt_i > 0)
				i++;
		}
	}
	while (i > 0)
	{
		ft_rotate_stack(a, b, -1, cmnd);
		i--;
	}
	ft_last_srtd(a, b);
}

void	ft_qsort_b(t_stack *a, t_stack *b, t_list **cmnd)
{
	int		pivot;
	int		i;

	i = 0;
	pivot = ft_get_pivot(ft_copy_stack(b));
	while (!ft_check_lower_nums(b, pivot, 'b', 0) 
			&& b->index > 3 + b->srt_i)
	{	
		if (b->num[b->index - 1] > pivot)
			ft_push(a, b, 0, cmnd);
		else
		{
			ft_rotate_stack(a, b, 2, cmnd);
			if (b->srt_i > 0)
				i++;
		}
	}
	while (i > 0)
	{
		ft_rotate_stack(a, b, -2, cmnd);
		i--;
	}
	ft_last_srtd(a, b);
}
