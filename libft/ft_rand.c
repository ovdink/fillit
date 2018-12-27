/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:25:13 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/25 20:45:26 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int			ft_my_count(long n)
{
	int				count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

unsigned long		ft_rand(int c)
{
	int				del;
	unsigned long	num;
	int				count;
	int				c2;

	num = (unsigned long)&num;
	c2 = c;
	while (c > 0)
	{
		del = 1;
		while (c)
		{
			del *= 10;
			c--;
		}
		num %= (del + 1);
		c--;
	}
	count = ft_my_count(num);
	if (num == 0)
		return (ft_rand((int)(&num)));
	if (c2 != count)
		return (((int)&num) % (del + 1));
	return (num);
}
