/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:56:54 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 19:31:11 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;

	if (size == (size_t)(-1))
		return (NULL);
	mem = (char *)malloc(size + 1);
	if (mem == 0)
		return (NULL);
	ft_bzero((void *)mem, size + 1);
	return ((void *)mem);
}
