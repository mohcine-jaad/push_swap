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

static t_list	*find_min(t_list *stack)
{
	t_list	*min_node;

	min_node = stack;
	while (stack)
	{
		if (*(int *)stack->content < *(int *)min_node->content)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

static t_list	*closer(t_list *list, t_list *node)
{
	t_list	*i;
	t_list	*target;
	int		diff;
	int		tmp;

	i = list;
	target = NULL;
	tmp = 0;
	while (i)
	{
		diff = *((int *)(node->content)) - *((int *)(i->content));
		if (diff < 0 && (tmp == 0 || diff > tmp))
		{
			tmp = diff;
			target = i;
		}
		i = i->next;
	}
	if (target == NULL)
		target = find_min(list);
	return (target);
}

void	ft_find_target(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->target_node = closer(*stack_a, tmp_b);
		tmp_b = tmp_b->next;
	}
}
