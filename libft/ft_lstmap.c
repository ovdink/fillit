/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:50:34 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 19:28:05 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*mem;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	mem = new;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = f(lst)))
		{
			while (mem->next)
			{
				new = mem->next;
				free(mem);
				mem = new;
			}
		}
		lst = lst->next;
		new = new->next;
	}
	return (mem);
}
