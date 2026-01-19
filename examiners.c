/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examiners.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-17 17:54:37 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-17 17:54:37 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "dynamic_array/dynamic_array.h"
#include "linked_list/linked_list.h"

int	ft_find_space(char *str)
{
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			return (1);
		str++;
	}
	return (0);
}

int	ft_is_invalidnumber(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!(*str))
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	isduplicated(t_list *list)
{
	t_list	*tmp;

	while (list->next)
	{
		tmp = list->next;
		while (tmp)
		{
			if (*((int *)(list->content)) == *((int *)(tmp->content)))
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

void	is_sorted(t_list **stack, t_array *arr)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)(tmp->next->content))
			return ;
		tmp = tmp->next;
	}
	ft_lstclear(stack, free);
	clear_array(arr, free);
	exit(0);
}
