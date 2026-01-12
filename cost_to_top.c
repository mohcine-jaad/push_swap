/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-06 16:00:07 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-06 16:00:07 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

void	ft_cost_to_top(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_node;
	int		lsize_b;
	int		lsize_a;
	int		index;

	lsize_b = ft_lstsize(stack_b);
	lsize_a = ft_lstsize(stack_a);
	current_node = stack_b;
	while (current_node)
	{
		index = ft_lstindex(stack_b, current_node);
		if (index <= (lsize_b / 2))
			current_node->cost_b = index;
		else
			current_node->cost_b = lsize_b - index;
		index = ft_lstindex(stack_a, current_node->target_node);
		if (index <= (lsize_a / 2))
			current_node->cost_a = index;
		else
			current_node->cost_a = lsize_a - index;
		current_node->total_cost = current_node->cost_a + current_node->cost_b;
		current_node = current_node->next;
	}
}
