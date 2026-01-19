/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjaad <mjaad@student.42.fr>                #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-27 11:55:20 by mjaad             #+#    #+#             */
/*   Updated: 2025-12-27 11:55:20 by mjaad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "dynamic_array/dynamic_array.h"
#include "linked_list/linked_list.h"
#include "rules/rules.h"

static int	get_argument(t_array *array, char **av)
{
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (ft_find_space(av[i]))
		{
			tmp = ft_split(av[i]);
			j = 0;
			if (!(*tmp))
			{
				free(tmp);
				return (1);
			}
			while (tmp[j])
				push_back(array, tmp[j++]);
			free(tmp);
		}
		else
			push_back(array, ft_strdup(av[i]));
		i++;
	}
	return (0);
}

static int	ft_examin(t_array *arr)
{
	size_t	index;
	char	*token;

	index = 0;
	while (index < arr->number_of_elememts)
	{
		token = (char *)get_element(arr, index++);
		if (ft_is_invalidnumber(token))
			return (1);
	}
	return (0);
}

static t_list	*build_list(t_array *arr)
{
	t_list	*list;
	size_t	counter;
	long	tmp;
	int		*value;

	counter = 0;
	list = NULL;
	while (counter < arr->number_of_elememts)
	{
		tmp = ft_atol((char *)arr->data[counter]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		value = malloc(sizeof(int));
		*value = (int)tmp;
		ft_lstadd_back(&list, ft_lstnew(value));
		counter++;
	}
	return (list);
}

static int	initialise(t_array **arr, t_list **stack_a, char **av)
{
	if (get_argument(*arr, av))
		return (1);
	if (ft_examin(*arr))
		return (1);
	*stack_a = build_list(*arr);
	if (!*stack_a)
		return (1);
	if (isduplicated(*stack_a))
		return (1);
	return (0);
}

int	main(int counter, char **av)
{
	t_array	*arr;
	t_list	*stack_a;
	t_list	*stack_b;

	if (counter < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	arr = creat_array();
	if (initialise(&arr, &stack_a, av))
	{
		ft_putstr_fd("Error\n", 1);
		clear_array(arr, free);
		ft_lstclear(&stack_a, free);
		return (1);
	}
	is_sorted(&stack_a, arr);
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a, free);
	clear_array(arr, free);
	return (0);
}
