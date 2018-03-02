/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:41:01 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:30:35 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_prnterror(t_stack *a, char *instr, t_list *cmnd)
{
	write(2, "Error\n", 6);
	ft_del_stack(a);
	ft_lstdel(&cmnd, &ft_dellst);
	ft_strdel(&instr);
	exit(-1);
}

int			ft_check_doubles(t_stack *a)
{
	size_t		i;

	i = 1;
	while (i < a->index)
	{
		if (a->num[0] == a->num[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_validator(char **nums, int flag, int argc)
{
	int		i;
	int		j;

	i = 1 + flag;
	while (i < argc)
	{
		j = 0;
		while (nums[i][j])
		{
			if (ft_isdigit(nums[i][j]) || nums[i][0] == '-'
			|| nums[i][0] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
