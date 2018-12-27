/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:21:40 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/27 13:42:19 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				change_figure(t_tetra **tetra)
{
	unsigned char	**tab;
	int				i;
	int				j;

	i = 0;
	tab = (unsigned char**)malloc(sizeof(unsigned char*) *
			((*tetra)->p[1] - (*tetra)->p[0] + 1));
	while (i < ((*tetra)->p[1] - (*tetra)->p[0] + 1))
	{
		tab[i] = (unsigned char*)malloc(sizeof(unsigned char) *
				((*tetra)->p[3] - (*tetra)->p[2] + 1));
		j = 0;
		while (j < ((*tetra)->p[3] - (*tetra)->p[2] + 1))
		{
			tab[i][j] = (*tetra)->figure[i + (*tetra)->p[0]][j +
				(*tetra)->p[2]];
			j++;
		}
		i++;
	}
	free((*tetra)->figure);
	(*tetra)->figure = tab;
}

void				points(t_tetra **tetra)
{
	int				i;
	int				j;

	i = -1;
	(*tetra)->p[0] = 3;
	(*tetra)->p[1] = 0;
	(*tetra)->p[2] = 3;
	(*tetra)->p[3] = 0;
	while (i++ < 3)
	{
		j = -1;
		while (j++ < 3)
			if ((*tetra)->figure[i][j] == (*tetra)->symb)
			{
				if (i < (*tetra)->p[0])
					(*tetra)->p[0] = i;
				if (i > (*tetra)->p[1])
					(*tetra)->p[1] = i;
				if (j < (*tetra)->p[2])
					(*tetra)->p[2] = j;
				if (j > (*tetra)->p[3])
					(*tetra)->p[3] = j;
			}
	}
	change_figure(tetra);
}

int					get_figure(char *str, t_tetra **tetra)
{
	int				h;
	int				w;
	int				i;

	h = -1;
	i = 0;
	(*tetra)->figure = (unsigned char **)malloc(sizeof(unsigned char *) * 4);
	while (++h < 4)
	{
		(*tetra)->figure[h] = (unsigned char*)malloc(sizeof(unsigned char) * 4);
		w = -1;
		while (++w < 4)
		{
			if (str[i] == '#')
				(*tetra)->figure[h][w] = (*tetra)->symb;
			else
				(*tetra)->figure[h][w] = str[i];
			i++;
		}
		i++;
	}
	if (!(check_sharp((*tetra)->figure, (*tetra)->symb)))
		return (0);
	points(tetra);
	return (1);
}

int					add_node(t_tetra **lst, char *str)
{
	t_tetra			*new_tetra;
	t_tetra			*to_end;
	static int		i;

	new_tetra = (t_tetra*)malloc(sizeof(t_tetra));
	new_tetra->symb = 'A' + (i++);
	if (!(get_figure(str, &new_tetra)))
		return (0);
	new_tetra->next = NULL;
	if (!(*lst))
	{
		*lst = new_tetra;
		return (1);
	}
	to_end = *lst;
	while (to_end->next)
		to_end = to_end->next;
	to_end->next = new_tetra;
	if (new_tetra->symb > 'Z')
		return (0);
	return (1);
}
