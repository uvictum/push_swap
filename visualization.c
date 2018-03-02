/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:59:35 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 18:31:46 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"

static int	ft_get_lstcmnd(t_list *cmnd, int flag)
{
	char	*str;

	if (flag < 2 || !cmnd)
		return (0);
	while (cmnd->next)
		cmnd = cmnd->next;
	str = cmnd->content;
	if (str[cmnd->content_size - 2] == 'a')
		return (1);
	else
		return (2);
}

void		ft_print_stack(t_stack *a, t_stack *b, int flag, t_list *cmnd)
{
	int		i;
	int		j;

	i = a->index - 1;
	j = b->index - 1;
	flag = ft_get_lstcmnd(cmnd, flag);
	while (i >= 0 || j >= 0)
	{
		if (j == i && i >= 0)
			ft_printf("%s[%d]  %s[%d]\n", (flag == 1 ? KRED : KNRM),
			a->num[i--], (flag == 2 ? KRED : KNRM), b->num[j--]);
		else if (j >= 0 && j > i)
			ft_printf("%s[ ] %s[%d]\n", KNRM, (flag == 2 ? KRED : KNRM),
			b->num[j--]);
		else if (i >= 0 && i > j)
		{
			ft_printf("%s[%d]  %s[ ]\n", (flag == 1 ? KRED : KNRM),
			a->num[i--], KNRM);
			flag = (flag == 2 ? 3 : flag);
		}
		flag = (flag == 3 ? 2 : 0);
	}
	ft_printf("%s________\n A    B \n", KNRM);
}
