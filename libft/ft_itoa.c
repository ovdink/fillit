/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:21:26 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/03 20:35:13 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_my_count(long n)
{
	int			count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	long int	num;
	int			size;
	char		*mem;

	size = ft_my_count(n);
	if (n < 0)
		num = -(long)n;
	else
		num = n;
	mem = ft_strnew(size);
	if (mem == 0)
		return (NULL);
	if (num == 0)
		mem[0] = '0';
	while (num != 0)
	{
		mem[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
	if (size == 1 && n)
		mem[0] = '-';
	return (mem);
}
