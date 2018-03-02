/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:03:02 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:28:31 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_qb_sort(t_stack *a, t_stack *b, int n, t_list **cmnd)
{
	int			pushed;

	if (b->index - b->srt_i > 3)
	{
		pushed = ft_qsort_b(a, b, cmnd);
		a->srt_i = a->index - pushed;
		ft_nsort(a, b, 'a', cmnd);
		b->srt_i = b->index - (n - pushed);
		ft_nsort(a, b, 'b', cmnd);
	}
	else
	{
		ft_sort_small(a, b, 'b', cmnd);
		ft_back_b(a, b, b->srt_i, cmnd);
	}
}

void			ft_nsort(t_stack *a, t_stack *b, char arg, t_list **cmnd)
{
	int			pushed;

	if (arg == 'a')
	{
		if (a->index - a->srt_i > 3)
		{
			pushed = ft_qsort_a(a, b, cmnd);
			ft_nsort(a, b, 'a', cmnd);
			b->srt_i = b->index - pushed;
			ft_nsort(a, b, 'b', cmnd);
		}
		else
			ft_sort_small(a, b, 'a', cmnd);
	}
	if (arg == 'b')
		ft_qb_sort(a, b, b->index - b->srt_i, cmnd);
}

static void		ft_rev(t_stack *a, char arg, int n, t_list **cmnd)
{
	while (n > 0)
	{
		ft_rotate_stack(a, a, (arg == 'a' ? -1 : -2), cmnd);
		n--;
	}
}

int				ft_qsort_a(t_stack *a, t_stack *b, t_list **cmnd)
{
	int			pivot;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pivot = ft_get_pivot(ft_copy_stack(a));
	while (!ft_check_lower_nums(a, pivot, 'a', 0))
	{
		if (a->num[a->index - 1] < pivot)
		{
			ft_push(a, b, 1, cmnd);
			j++;
		}
		else
		{
			ft_rotate_stack(a, b, 1, cmnd);
			if (a->srt_i > 0)
				i++;
		}
	}
	ft_rev(a, 'a', i, cmnd);
	return (j);
}

int				ft_qsort_b(t_stack *a, t_stack *b, t_list **cmnd)
{
	int			pivot;
	int			i;
	int			j;

	i = 0;
	j = 0;
	pivot = ft_get_pivot(ft_copy_stack(b));
	while (!ft_check_lower_nums(b, pivot, 'b', 0))
	{
		if (b->num[b->index - 1] > pivot)
		{
			ft_push(a, b, 0, cmnd);
			j++;
		}
		else
		{
			ft_rotate_stack(a, b, 2, cmnd);
			if (b->srt_i > 0)
				i++;
		}
	}
	ft_rev(b, 'b', i, cmnd);
	return (j);
}
