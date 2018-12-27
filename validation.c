/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:43:27 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/26 17:12:15 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_map(char *str, int *flag)
{
	int w;
	int sharp;

	if (!str)
		return (0);
	if (ft_strlen(str) < 20)
		return (0);
	w = 0;
	sharp = 0;
	while (str[w])
	{
		if (((w + 1) % 5 == 0) && str[w] != '\n')
			return (0);
		if (((w + 1) % 5 != 0) && (!(str[w] != '.' || str[w] != '#')))
			return (0);
		if (str[w] == '#')
			sharp++;
		w++;
	}
	if (!(str[20] == '\n' || str[20] == '\0') || sharp != 4)
		return (0);
	if (str[20] == '\0')
		*flag = 0;
	return (1);
}

int		check_sharp(unsigned char **tetra, char c)
{
	int w;
	int h;
	int contact;

	h = -1;
	contact = 0;
	while (++h < 4)
	{
		w = -1;
		while (++w < 4)
		{
			if (tetra[h][w] == c)
			{
				if (w < 3 && tetra[h][w + 1] == c)
					contact++;
				if (w > 0 && tetra[h][w - 1] == c)
					contact++;
				if (h > 0 && tetra[h - 1][w] == c)
					contact++;
				if (h < 3 && tetra[h + 1][w] == c)
					contact++;
			}
		}
	}
	return ((contact == 6 || contact == 8) ? 1 : 0);
}
