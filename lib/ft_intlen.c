/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmorguno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:12:25 by vmorguno          #+#    #+#             */
/*   Updated: 2017/11/14 16:31:12 by vmorguno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int	count;
	int grad;

	grad = 10;
	count = 1000000000;
	while (n / count == 0)
	{
		count = count / 10;
		grad--;
	}
	return (grad);
}