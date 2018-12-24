/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:43:16 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 19:28:42 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mem;

	mem = (t_list *)malloc(sizeof(t_list));
	if (!mem)
		return (NULL);
	if (content == NULL)
	{
		mem->content = NULL;
		mem->content_size = 0;
	}
	else
	{
		mem->content = ft_memalloc(content_size);
		if (mem->content == 0)
		{
			free(mem);
			return (0);
		}
		ft_memcpy(mem->content, content, content_size);
		mem->content_size = content_size;
	}
	mem->next = NULL;
	return (mem);
}
