/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgendry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:21:39 by sgendry           #+#    #+#             */
/*   Updated: 2018/12/04 19:29:25 by sgendry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_my_word(char const *s, char c)
{
	size_t		i;
	size_t		word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char		**ft_my(char **mem, const char *s, char c, size_t word)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (i < word)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		if (!(mem[i] = ft_strsub(s, 0, len)))
		{
			while (i)
			{
				free(mem[i]);
				i--;
			}
			return (NULL);
		}
		i++;
		s = s + len;
	}
	return (mem);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**mem;
	size_t		word;

	if (!s)
		return (NULL);
	word = ft_my_word(s, c);
	if (!(mem = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	mem[word] = 0;
	if (!(mem = ft_my(mem, s, c, word)))
	{
		free(mem);
		return (NULL);
	}
	return (mem);
}
