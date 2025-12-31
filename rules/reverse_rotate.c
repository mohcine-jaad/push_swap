/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.1337.ma>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-31 14:52:45 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-31 14:52:45 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

void	ft_reverse_rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;
	t_list	*tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
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
}
