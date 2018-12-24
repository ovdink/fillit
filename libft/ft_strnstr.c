/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:44:35 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/03 15:52:58 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	j;
	size_t	k;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	if (*s2 == '\0')
		return (s1);
	k = 0;
	while (s1[k] && k < len)
	{
		i = k;
		j = 0;
		while (s1[i] == s2[j] && i < len)
		{
			i++;
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + k);
		}
		k++;
	}
	return (0);
}
