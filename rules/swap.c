#include "linked_list/linked_list.h"

void	ft_swap(t_list **stack)
{
	t_list	*node2;
	t_list	*node3;

	if(!stack || !(*stack) || !((*stack)->next))
		return;
	node2 = (*stack)->next;
	node3 = (*stack)->next->next;
	(*stack)->next = node3;
	node2->next = *stack;
	*stack = node2;
}