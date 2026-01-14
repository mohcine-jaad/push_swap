/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finde_cheapest_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-08 13:48:09 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-08 13:48:09 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

t_list *find_cheapest_node(t_list *stack)
{
	t_list	*cheapest;
	int		min;

	min = stack->total_cost;
	cheapest = stack;
	while (stack)
	{
		if (stack->total_cost < min)
		{
			min = stack->total_cost;
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
