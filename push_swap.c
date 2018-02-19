/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 13:03:35 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/19 19:22:33 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack 	*a;
	t_stack		*b;
	t_list		*cmnd;
	int			pivot;

	a = ft_read_stack_a(argc, argv, 0);
	b = (t_stack *)ft_memalloc(sizeof(t_stack));
	b->num = (int *)ft_memalloc(sizeof(int) * argc - 1);
//	ft_qsort(a, b, 'a', &cmnd);
	ft_nsort(a, b, &cmnd);
	ft_back_b(a, b, &cmnd);
//	ft_optimize_commands(cmnd);
	ft_print_commands(a, b, cmnd);
}




