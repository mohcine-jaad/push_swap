#include "linked_list/linked_list.h"

void	ft_rotate(t_list **stack)
{
	t_list	*top;
	t_list	*bottom;

	top = *stack;
	bottom = *stack;
	while (bottom->next)
		bottom = bottom->next;
	*stack = (*stack)->next;
	bottom->next = top;
	top->next = NULL;
}