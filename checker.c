/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:12:04 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/13 19:18:30 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_funcs funcs[] =
	{
	{"sa", &ft_swp, 0}, {"sb", &ft_swp, 1},
	{"ss", &ft_swp, 2}, {"pa", &ft_push, 0},
	{"pb", &ft_push, 1}, {"ra", &ft_rotate_stack, 1},
	{"rb", &ft_rotate_stack, 2}, {"rr", &ft_rot_both, 0},
	{"rra", &ft_rotate_stack, -1},
	{"rrb", &ft_rotate_stack, -2}, {"rrr", &ft_rot_both, 1}
	};
	t_stack	*a;
	t_stack	*b;
	int		flag;

	flag = 0;
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'v')
		flag = 1;	
	a = ft_read_stack_a(argc, argv, flag);
	b = (t_stack *)ft_memalloc(sizeof(t_stack));
	b->num = (int *)ft_memalloc(sizeof(int) * argc - 1);
	ft_operate(a, b, funcs, flag);
	if (b->index == 0 && argc - 1 - flag == a->index 
		&& ft_check_sort(a, 0))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(b->num);
	free(b);
//	system("leaks checker");
	return (0);
}


void	ft_operate(t_stack *a, t_stack *b, t_funcs *funcs, int flag)
{
	int		i;
	char	*instr;
	t_list	*cmnd;

	cmnd = NULL;
	while (get_next_line(0, &instr))
	{
		i = 0;
		while (i < 11)
		{
			if (!ft_strcmp(instr, funcs[i].name))
			{
				funcs[i].fptr(a, b, funcs[i].arg, &cmnd);
				if (flag)
					ft_print_stack(a, b);
				break;
			}
			i++;
		}
		if (i == 11)
		{
			write(2, "Error\n", 6);
			free(a->num);
			free(a);
			ft_lstdel(&cmnd, &ft_dellst);
			ft_strdel(&instr);
			exit(-1);
		}
		free(instr);
	}
	ft_lstdel(&cmnd, &ft_dellst);
	return(ft_strdel(&instr));
}


