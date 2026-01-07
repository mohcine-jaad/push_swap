/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-05 09:04:01 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-05 09:04:01 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

#include <stdio.h>

static int closer(t_list **list, int node)
{
    t_list  *i;
    int     tmp;
    int     target;
    int     diff;

    i = *list;
    tmp = 0;
    while (i)
    {
        target = *((int *)(i->content));
        diff = node - target;
        if (diff < 0 && (tmp == 0 || diff > tmp))
            tmp = diff;
        i = i->next;
    }
    if (!tmp)
		return (*((int *)(*list)->content));
    else
        return (node - tmp); 
}

void	ft_find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->target_node = closer(stack_a, *(int *)(tmp_b->content));
		tmp_b = tmp_b->next;
	}
}
