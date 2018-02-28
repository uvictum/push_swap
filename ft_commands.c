/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:39:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/28 19:52:47 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_commands(t_stack *a, t_stack *b, t_list *cmnd)
{
	{
		while (cmnd)
		{
			write(1, cmnd->content, cmnd->content_size);
			cmnd = cmnd->next;
		}
	}
	ft_lstdel(&cmnd, &ft_dellst);
	free(a->num);
	free(a);
	free(b->num);
	free(b);
}
