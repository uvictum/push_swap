/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:13:21 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:29:15 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_check_sort(t_stack *a, int n)
{
	if (n < 0)
		n = 0;
	while (n < a->index - 1)
	{
		if (a->num[n] > a->num[n + 1])
			n++;
		else
			return (0);
	}
	return (1);
}

void		ft_back_b(t_stack *a, t_stack *b, int n, t_list **cmnd)
{
	while (b->index > n)
		ft_push(a, b, 0, cmnd);
}

int			ft_check_bsort(t_stack *b, int n)
{
	if (n < 0)
		n = 0;
	while (n < b->index - 1)
	{
		if (b->num[n] < b->num[n + 1])
			n++;
		else
			return (0);
	}
	return (1);
}

int			ft_check_lower_nums(t_stack *a, int pivot, char stack, int flag)
{
	int		i;

	i = a->srt_i;
	if (stack == 'a')
	{
		while (i < a->index + flag)
		{
			if (a->num[i] < pivot)
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < a->index + flag)
		{
			if (a->num[i] > pivot)
				return (0);
			i++;
		}
		return (1);
	}
}

int			ft_get_pivot(t_stack *a)
{
	int		buf;
	int		i;
	int		s;

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
	s = (a->srt_i + ((a->index - a->srt_i) / 2));
	i = a->num[s + ((a->index - a->srt_i) % 2 == 0 ? -1 : 0)];
	free(a->num);
	free(a);
	return (i);
}
