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
# include "linked_list/linked_list.h"

void	ft_push(t_list **dest, t_list **src);
void	ft_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack);
void	ft_swap(t_list **stack);

#endif