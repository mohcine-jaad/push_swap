/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-27 12:08:19 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-27 12:08:19 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "linked_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->target_node = -1;
	node->next = NULL;
	return (node);
}
