/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:59 by sgendry           #+#    #+#             */
/*   Updated: 2018/11/30 19:46:56 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (!s)
		return (NULL);
	mem = ft_strnew(len);
	if (mem == 0)
		return (NULL);
	ft_strncpy(mem, s + start, len);
	return (mem);
}
