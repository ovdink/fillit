/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:09:45 by sgendry           #+#    #+#             */
/*   Updated: 2018/11/29 15:32:28 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	unsigned int	i;
	char			*mem;
	char			*mem_begin;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	mem = ft_strnew(len);
	mem_begin = mem;
	if (mem == 0)
		return (NULL);
	while (s[i])
	{
		*mem = f(i, s[i]);
		mem++;
		i++;
	}
	return (mem_begin);
}
