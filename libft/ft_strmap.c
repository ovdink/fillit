/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:52:33 by sgendry           #+#    #+#             */
/*   Updated: 2018/11/29 16:06:51 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*mem;
	char	*mem_begin;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	mem = ft_strnew(len);
	if (!mem)
		return (NULL);
	mem_begin = mem;
	if (mem == 0)
		return (NULL);
	while (*s)
	{
		*mem = f(*s);
		mem++;
		s++;
	}
	return (mem_begin);
}
