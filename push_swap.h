/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:37:05 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/12 18:21:41 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_stack {
	int			*num;
	size_t		index;
	size_t		srt_i;
}				t_stack;

typedef struct 	s_funcs {
	char 		name[4];
	void 		(*fptr)(t_stack *a, t_stack *b, int arg, t_list **cmnd);
	int			arg;
}				t_funcs;

void		ft_operate(t_stack *a, t_stack *b, t_funcs *funcs, int flag);
t_stack		*ft_read_stack_a(int argc, char **argv, int flag);
int			ft_check_sort(t_stack *a, int n);
void		ft_swap_t(t_stack *stack, size_t index_f, size_t index_s);
void		ft_swp(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd);
void		ft_push(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd);
void		ft_rot_u(t_stack *stack);
void		ft_rot_d(t_stack *stack);
void		ft_rotate_stack(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd);
void		ft_rot_both(t_stack *stack_a, t_stack *stack_b, int arg, t_list **cmnd);
void		ft_print_stack(t_stack *a, t_stack *b);

#endif
