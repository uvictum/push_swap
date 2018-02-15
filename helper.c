/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:13:21 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/15 17:50:05 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_read_stack_a(int argc, char **argv, int flag)
{
	int i;
	t_stack	*a;

	i = argc - 1 - flag;
	a = (t_stack *)ft_memalloc(sizeof(t_stack));
	a->num = (int *)ft_memalloc(sizeof(int) * (i));
	while (i > 0)
	{
		a->num[i - 1] = ft_atoi(argv[argc - i]);
		a->index++;
		if (a->num[i - 1] == 0 && argv[argc - i][0] != '0')
		{
			write(2, "Error\n", 6);
			free(a->num);
			free(a);
			exit(-1);
		}
		i--;
	}
	return (a);
}

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



void	ft_back_b(t_stack *a, t_stack *b, t_list **cmnd)
{
	while (b->index > 0)
		ft_push(a, b, 0, cmnd);
}
	
int		ft_check_bsort(t_stack *b, int n)
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

int		ft_check_lower_nums(t_stack *a, int pivot, char stack, int flag)
{
	int		i;

	i = a->srt_i;
	if (stack == 'a')
	{
		while(i < a->index - flag)
		{
			if (a->num[i] < pivot)
				return (0);
			i++;
		}
		return(1);
	}
	else
		while (i < a->index - flag)
		{
			if (a->num[i] > pivot)
			   return (0);
			i++;
		}	
		return (1);

// убрать отсюда стак а стак б проверять только меньшие цифры, в разных стаках важен разный ответ
}

