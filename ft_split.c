/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-22 15:43:06 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-22 15:43:06 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_whitespace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static size_t	ft_countword(char const *s)
{
	size_t	counter;
	int		flag;

	counter = 0;
	flag = 0;
	while (*s)
	{
		if (is_whitespace(*s++))
			flag = 0;
		else if (!flag)
		{
			flag = 1;
			counter++;
		}
	}
	return (counter);
}

static void	*ft_free_previus(char **base_address, char **increment_address)
{
	int	i;

	i = 0;
	while (base_address + i < increment_address)
		free(base_address[i++]);
	free(base_address);
	return (NULL);
}

static size_t	ft_wordlen(const char *w)
{
	size_t	len;

	len = 0;
	while (*w && !(is_whitespace(*w)))
	{
		len++;
		w++;
	}
	return (len);
}

char	**ft_split(char const *s)
{
	char		**table;
	char		**base_address;
	size_t		len;

	if (!s)
		return (0);
	table = (char **)malloc(sizeof(char *) * (ft_countword(s) + 1));
	if (!table)
		return (NULL);
	base_address = table;
	while (*s)
	{
		while (*s && is_whitespace(*s))
			s++;
		if (!(*s))
			break ;
		len = ft_wordlen(s);
		*table = ft_substr(s, 0, len);
		s += len;
		if (!(*table))
			return (ft_free_previus(base_address, table));
		table++;
	}
	*table = NULL;
	return (base_address);
}
