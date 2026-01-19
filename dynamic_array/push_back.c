/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-17 17:20:24 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-17 17:20:24 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

void	push_back(t_array *arr, void *element)
{
	if (arr->number_of_elememts == arr->current_size)
		resize_array(arr);
	arr->data[arr->number_of_elememts] = element;
	arr->number_of_elememts++;
}
