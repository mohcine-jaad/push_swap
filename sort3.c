/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 16:56:04 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-01 16:56:04 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

void	sort3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = *((int *)(*stack_a)->content);
	b = *((int *)(*stack_a)->next->content);
	c = *((int *)(*stack_a)->next->next->content);
	if (a < b && a < c && b > c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a > b && a < c && b < c)
		sa(stack_a);
	else if (a < b && a > c && b > c)
		rra(stack_a);
	else if (a > b && a > c && b < c)
		ra(stack_a);
	else if (a > b && a > c && b > c)
	{
		ra(stack_a);
		sa(stack_a);
	}
}
