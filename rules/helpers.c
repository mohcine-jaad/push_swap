/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 14:32:59 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-01 14:32:59 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

int	ft_push(t_list **dest, t_list **src)
{
	t_list	*tmp;

	if (!src || !*src )
		return (1);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	return (0);
}

int	ft_reverse_rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;
	t_list	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return (1);
	top = *stack;
	bottom = ft_lstlast(*stack);
	tmp = *stack;
	while (1)
	{
		if (tmp->next->next == NULL)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	bottom->next = top;
	*stack = bottom;
	return (0);
}

int	ft_rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	if (!stack || !(*stack) || !((*stack)->next))
		return (1);
	top = *stack;
	bottom = ft_lstlast(*stack);
	*stack = (*stack)->next;
	bottom->next = top;
	top->next = NULL;
	return (0);
}

int	ft_swap(t_list **stack)
{
	t_list	*node2;
	t_list	*node3;

	if (!stack || !(*stack) || !((*stack)->next))
		return (1);
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	(*stack)->next = node3;
	node2->next = *stack;
	*stack = node2;
	return (0);
}
