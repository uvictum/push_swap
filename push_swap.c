/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:23:04 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 12:23:06 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_list		*cmnd;
	int			pivot;

	a = ft_read_stack_a(argc, argv, 0);
	b = (t_stack *)ft_memalloc(sizeof(t_stack));
	b->num = (int *)ft_memalloc(sizeof(int) * argc - 1);
	ft_nsort(a, b, 'a', &cmnd);
	ft_back_b(a, b, 0, &cmnd);
	ft_optimize_commands(cmnd);
	ft_print_commands(a, b, cmnd);
	return (0);
}
