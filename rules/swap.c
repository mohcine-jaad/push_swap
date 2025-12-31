/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.1337.ma>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-31 14:55:13 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-31 14:55:13 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

void	ft_swap(t_list **stack)
{
	t_list	*node2;
	t_list	*node3;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	(*stack)->next = node3;
	node2->next = *stack;
	*stack = node2;
}
