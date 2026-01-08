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
static int	get_index(t_list *stack, int node)
{
	int		index;

	index = 0;
	while (stack)
	{
		if (*((int *)(stack->content)) == node)
			return (index);
		stack = stack->next;
		index++;
	}

	return (index);
}

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
		index = get_index(stack_b, *((int *)(current_node->content)));
		if (index <= (lsize_b / 2))
			current_node->cost_b = index;
		else
			current_node->cost_b = lsize_b - index;
		index = get_index(stack_a, current_node->target_node);
		if (index <= (lsize_a / 2))
			current_node->cost_a = index;
		else
			current_node->cost_a = lsize_a - index;
		current_node->total_cost = current_node->cost_a + current_node->cost_b;
		current_node = current_node->next;
	}
}
