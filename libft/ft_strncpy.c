/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:44:25 by sgendry           #+#    #+#             */
/*   Updated: 2018/11/26 22:45:34 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*a;
	char	*b;

	a = dst;
	b = (char *)src;
	while (*b && len)
	{
		*a++ = *b++;
		len--;
	}
	while (len--)
		*a++ = '\0';
	return (dst);
}
