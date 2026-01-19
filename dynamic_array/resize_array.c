/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-17 17:16:48 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-17 17:16:48 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

void	resize_array(t_array *arr)
{
	void	*tmp;

	arr->current_size *= arr->capacity;
	arr->capacity *= 2;
	tmp = ft_calloc(sizeof(void *), (arr->current_size));
	ft_memcpy(tmp, arr->data, (sizeof(void *) * (arr->number_of_elememts)));
	free(arr->data);
	arr->data = tmp;
}
