/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-17 17:26:35 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-17 17:26:35 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

t_array	*creat_array(void)
{
	t_array	*arr;

	arr = malloc(sizeof(t_array));
	arr->current_size = 1025;
	arr->capacity = 2;
	arr->number_of_elememts = 0;
	arr->data = ft_calloc(sizeof(void *), (arr->current_size));
	return (arr);
}
