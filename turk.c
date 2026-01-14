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

static void	optimal_move(t_list **a, t_list **b, int *idx_b, int *idx_a)
{
	int	size_b;
	int	size_a;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if ((*idx_b >= (size_b / 2)) && (*idx_a >= (size_a / 2)))
	{
		while (*idx_a < size_a && *idx_b < size_b)
		{
			rrr(a, b);
			(*idx_a)++;
			(*idx_b)++;
		}
	}
	else if ((*idx_b < (size_b / 2)) && (*idx_a < (size_a / 2)) )
	{
		while (*idx_a > 0 && *idx_b > 0)
		{
			rr(a, b);
			(*idx_a)--;
			(*idx_b)--;
		}
	}
}
static void	ft_to_top(t_list **a, t_list **b, t_list *node)
{
	int	inode;
	int	itarget;
	int	size_b;
	int	size_a;

	size_b = ft_lstsize(*b);
	size_a = ft_lstsize(*a);
	inode = ft_lstindex(*b, node);
	itarget = ft_lstindex(*a, node->target_node);
	optimal_move(a, b, &inode, &itarget);
	if (inode >= (size_b / 2))
		while (inode++ < size_b)
			rrb(b);
	else
		while (inode-- > 0)
			rb(b);
	if (itarget >= (size_a / 2))
		while (itarget++ < size_a)
			rra(a);
	else
		while (itarget-- > 0)
			ra(a);
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
		ft_to_top(stack_a, stack_b, cheapest_node);
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
