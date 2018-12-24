/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:01:55 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 19:34:08 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *a;
	unsigned char *b;

	if (dst == src)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (a > b)
	{
		while (len)
		{
			a[len - 1] = b[len - 1];
			len--;
		}
	}
	while (len--)
		*a++ = *b++;
	return (dst);
}
