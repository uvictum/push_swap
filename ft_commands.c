/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:39:58 by vmorguno          #+#    #+#             */
/*   Updated: 2018/02/13 18:39:20 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void		ft_optimize_commands(t_list *cmnd)
//{
//}

void		ft_print_commands(t_stack *a, t_stack *b, t_list *cmnd)
{
	//if (ft_check_sort(a, a->srt_i) && b->index == 0)
//	{
		while (cmnd)
		{
			write(1, cmnd->content, cmnd->content_size);
			cmnd = cmnd->next;
		}
//	}
//	else 
//		ft_printf("need to check algo again\n");
	ft_lstdel(&cmnd, &ft_dellst);
	free(a->num);
	free(a);
	free(b->num);
	free(b);
}

