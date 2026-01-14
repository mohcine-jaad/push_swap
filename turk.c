/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-08 14:29:48 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-08 14:29:48 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

static t_list *find_min(t_list *stack)
{
    t_list *min_node = stack;
    while (stack)
    {
        if (*(int*)stack->content < *(int*)min_node->content)
            min_node = stack;
        stack = stack->next;
    }
    return min_node;
}

static void	ft_move_to_top(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	int	inode;
	int	itarget;
	int	size;

	size = ft_lstsize(*stack_b);
	inode = ft_lstindex(*stack_b, cheapest_node);
	if (inode >= (size / 2))
		while (inode++ < size)
			rrb(stack_b);
	else
		while (inode-- > 0)
			rb(stack_b);
	size = ft_lstsize(*stack_a);
	itarget = ft_lstindex(*stack_a, cheapest_node->target_node);
	if (itarget >= (size / 2))
		while (itarget++ < size)
			rra(stack_a);
	else
		while (itarget-- > 0)
			ra(stack_a);
}
void	turk(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;
	t_list	*min_node;
	int		index;
	int		size;

	while (*stack_b)
	{
		ft_find_target(stack_a, stack_b);
		ft_cost_to_top(*stack_a, *stack_b);
		cheapest_node = find_cheapest_node(*stack_b);
		ft_move_to_top(stack_a, stack_b, cheapest_node);
		pa(stack_a, stack_b);
	}

	min_node = find_min(*stack_a);
    index = ft_lstindex(*stack_a, min_node);
    size = ft_lstsize(*stack_a);
    
    if (index <= size / 2)
        while (index-- > 0)
            ra(stack_a);
    else
        while (index++ < size)
            rra(stack_a);
}
