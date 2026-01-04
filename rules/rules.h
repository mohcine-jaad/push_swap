/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.1337.ma>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-31 14:56:09 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-31 14:56:09 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RULES_H
# define RULES_H
# include "../linked_list/linked_list.h"

int	ft_push(t_list **dest, t_list **src);
int	ft_rotate(t_list **stack);
int	ft_reverse_rotate(t_list **stack);
int	ft_swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **dest, t_list **src);
void	pb(t_list **dest, t_list **src);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

#endif