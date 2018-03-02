/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:00:57 by vmorguno          #+#    #+#             */
/*   Updated: 2018/03/02 16:48:48 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_check_ops(char *current, char *next)
{
	if ((!ft_strcmp(current, "rrb\n") && !ft_strcmp(next, "rb\n")) ||
		(!ft_strcmp(current, "rra\n") && !ft_strcmp(next, "ra\n")) ||
		(!ft_strcmp(current, "rb\n") && !ft_strcmp(next, "rrb\n")) ||
		(!ft_strcmp(current, "ra\n") && !ft_strcmp(next, "rra\n")) ||
		(!ft_strcmp(current, "sa\n") && !ft_strcmp(next, "sa\n")) ||
		(!ft_strcmp(current, "sb\n") && !ft_strcmp(next, "sb\n")) ||
		(!ft_strcmp(current, "pa\n") && !ft_strcmp(next, "pb\n")) ||
		(!ft_strcmp(current, "pb\n") && !ft_strcmp(next, "pa\n")))
		return (1);
	else if ((!ft_strcmp(current, "rrb\n") && !ft_strcmp(next, "rra\n")) ||
		(!ft_strcmp(current, "rra\n") && !ft_strcmp(next, "rrb\n")) ||
		(!ft_strcmp(current, "rb\n") && !ft_strcmp(next, "ra\n")) ||
		(!ft_strcmp(current, "ra\n") && !ft_strcmp(next, "rb\n")) ||
		(!ft_strcmp(current, "sa\n") && !ft_strcmp(next, "sb\n")) ||
		(!ft_strcmp(current, "sb\n") && !ft_strcmp(next, "sa\n")))
		return (2);
	else
		return (0);
}

static int		ft_shortcmnds(t_list *cmnd)
{
	t_list		*buf;
	char		*str;

	buf = cmnd->next->next;
	ft_lstdelone(&cmnd->next, &ft_dellst);
	cmnd->next = buf;
	str = (char *)cmnd->next->content;
	if (str[0] == 's')
		str[1] = 's';
	else if (str[0] == 'r' && str[1] == 'r' && str[2] != '\n')
		str[2] = 'r';
	else
		str[1] = 'r';
	return (1);
}

int				ft_cmnd_optimizer(t_list *cmnd)
{
	int			i;
	t_list		*buf;
	char		*str;

	i = 0;
	while (cmnd && cmnd->next && cmnd->next->next)
	{
		if (ft_check_ops(cmnd->next->content, cmnd->next->next->content) == 1)
		{
			buf = cmnd->next->next->next;
			ft_lstdelone(&cmnd->next->next, &ft_dellst);
			ft_lstdelone(&cmnd->next, &ft_dellst);
			cmnd->next = buf;
			i = 1;
		}
		else if (ft_check_ops(cmnd->next->content,
		cmnd->next->next->content) == 2)
			i = ft_shortcmnds(cmnd);
		cmnd = cmnd->next;
	}
	return (i);
}

int				ft_cmnd_short(t_list *cmnd)
{
	int			i;
	t_list		*buf;
	char		*str;

	i = 0;
	while (cmnd && cmnd->next && cmnd->next->next && cmnd->next->next->next)
	{
		if ((!ft_strcmp(cmnd->next->content, "ra\n")
		&& !ft_strcmp(cmnd->next->next->content, "pb\n")
		&& !ft_strcmp(cmnd->next->next->next->content, "rra\n")) ||
		(!ft_strcmp(cmnd->next->content, "rb\n")
		&& !ft_strcmp(cmnd->next->next->content, "pa\n")
		&& !ft_strcmp(cmnd->next->next->next->content, "rrb\n")))
		{
			str = cmnd->next->content;
			str[0] = 's';
			buf = cmnd->next->next->next->next;
			ft_lstdelone(&cmnd->next->next->next, &ft_dellst);
			cmnd->next->next->next = buf;
			i = 1;
		}
		cmnd = cmnd->next;
	}
	return (i);
}

void			ft_optimize_commands(t_list *cmnd)
{
	while (ft_cmnd_optimizer(cmnd))
		continue;
	while (ft_cmnd_short(cmnd))
		continue;
}
