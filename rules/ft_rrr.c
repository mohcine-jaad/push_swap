/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-01 15:14:29 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-01 15:14:29 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rules.h"

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_reverse_rotate(stack_a))
		return ;
	if (ft_reverse_rotate(stack_b))
		return ;
	write(1, "rrr\n", 4);
}
