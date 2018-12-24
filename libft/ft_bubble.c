/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 20:09:04 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 21:28:15 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bubble(char **c)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (c[i])
	{
		j = i + 1;
		while (c[j])
		{
			if (ft_strcmp(c[i], c[j]) > 0)
			{
				tmp = c[i];
				c[i] = c[j];
				c[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
