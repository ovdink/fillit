/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:31:39 by lschambe          #+#    #+#             */
/*   Updated: 2018/12/27 16:53:17 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid(char *file, t_tetra **tetra)
{
	int					fd;
	char				buf[BUFF_SIZE + 1];
	int					ret;
	int					flag;

	fd = open(file, O_RDONLY);
	flag = 1;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (!flag)
			return (0);
		buf[ret] = '\0';
		if (!(check_map(buf, &flag)))
			return (0);
		if (!(add_node(tetra, buf)))
			return (0);
	}
	if (flag)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_tetra *tetra;
	int		size;

	size = 2;
	if (argc != 2)
	{
		ft_putstr("usage ./fillit target_file");
		return (0);
	}
	if (!(valid(argv[1], &tetra)))
	{
		ft_putstr("error\n");
		return (0);
	}
	solut(tetra, size);
	return (0);
}
