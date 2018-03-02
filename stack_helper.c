/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:39:22 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 19:34:04 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_atoi_simple(const char *str)
{
	int			sign;
	long int	res;
	char		*buf;

	buf = (char *)str;
	res = 0;
	sign = *buf == '-' ? -1 : 1;
	if (*buf == '+' || *buf == '-')
		buf++;
	while (*buf)
	{
		res = res * 10;
		res = res + (*buf - 48);
		buf++;
	}
	if (res > MAX_INT || res < MIN_INT)
		return (0);
	return ((int)(res * sign));
}

void			ft_del_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->num);
		free(stack);
		stack = NULL;
	}
}

t_stack			*ft_read_stack_a(int argc, char **argv, int flag)
{
	int			i;
	t_stack		*a;

	flag = (flag > 0 ? 1 : 0);
	i = argc - 1 - flag;
	if (!ft_validator(argv, flag, argc))
		ft_prnterror(NULL, NULL, NULL);
	a = (t_stack *)ft_memalloc(sizeof(t_stack));
	a->num = (int *)ft_memalloc(sizeof(int) * (i));
	while (i > 0)
	{
		a->num[i - 1] = ft_atoi_simple(argv[argc - i]);
		a->index++;
		if (a->num[i - 1] == 0 && argv[argc - i][0] != '0')
			ft_prnterror(a, NULL, NULL);
		i--;
	}
	if (ft_check_doubles(a))
		ft_prnterror(a, NULL, NULL);
	return (a);
}

t_stack			*ft_copy_stack(t_stack *a)
{
	t_stack		*stack;
	size_t		i;

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
	return (stack);
}
