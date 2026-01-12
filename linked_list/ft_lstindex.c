/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-08 15:56:05 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-08 15:56:05 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	ft_lstindex(t_list *lst, t_list *node)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst == node)
			return (index);
		lst = lst->next;
		index++;
	}
	return (-1);
}
