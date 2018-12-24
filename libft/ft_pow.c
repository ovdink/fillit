/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:26:56 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/30 14:39:05 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, unsigned int p)
{
	long int		i;
	long int		a;
	unsigned int	check;

	i = 1;
	a = n;
	check = a;
	if (n == 0)
		return (0);
	if (p == 0)
		return (1);
	while (i < p)
	{
		check = a;
		a = a * n;
		if (check < a && n < 0)
			return (0);
		if (check > a && n > 0)
			return (-1);
		i++;
	}
	return (a);
}
