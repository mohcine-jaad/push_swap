/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-01-17 17:28:12 by mjaad             #+#    #+#             */
/*   Updated: 2026-01-17 17:28:12 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynamic_array.h"

void	clear_array(t_array *obj, void (*delelements)(void *))
{
	size_t	i;

	i = 0;
	if (delelements)
	{
		while (i < obj->number_of_elememts)
		{
			delelements(get_element(obj, i));
			i++;
		}
	}
	free(obj->data);
	free(obj);
}
