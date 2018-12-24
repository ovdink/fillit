/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:45:11 by lschambe          #+#    #+#             */
/*   Updated: 2018/11/30 14:01:56 by lschambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *c)
{
	int i;
	int len;
	int j;
	int lenc;

	i = 0;
	len = 0;
	lenc = 0;
	while (s[len] != '\0')
		len++;
	while (c[lenc] != '\0')
		lenc++;
	while (i < len + 1)
	{
		j = 0;
		while (j <= lenc)
		{
			if (s[i] == c[j])
				return ((char*)(s + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
