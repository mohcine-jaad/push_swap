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

void	delelements(void *elem)
{
	free(elem);
}

int	get_argument(t_array *array, char **av)
{
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		if (find_space(av[i]))
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

int	ft_examin(t_array *arr)
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

t_list	*build_list(t_array *arr)
{
	t_list *list;
	size_t	counter;
	long	tmp;
	int *value;

	counter = 0;
	list = NULL;
	while(counter < arr->number_of_elememts)
	{
		tmp = ft_atol((char*)arr->data[counter]);
		if (tmp < INT_MIN || tmp > INT_MAX)
		{
			ft_lstclear(&list, delelements);
			return NULL;
		}
		value = malloc(sizeof(int));
		*value = (int)tmp;
		ft_lstadd_back(&list, ft_lstnew(value));
		counter++;
	}
	return (list);
}

int	main(int counter, char **av)
{
	t_array	*arr;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*temp;
	int i = 4;

	arr = creat_array();
	(void)counter;
	if (get_argument(arr, av) || ft_examin(arr) || !(stack_a = build_list(arr)) || isduplicated(stack_a))
	{
		ft_putstr_fd("Error\n", 1);
		clear_array(arr, delelements);
		return (1);
	}
	stack_b = NULL;
	while (i--)
		pb(&stack_b, &stack_a);
	sort(&stack_a);
	temp = stack_a;
	while (temp)
	{
		printf("(%d)", *(int *)(temp->content));
		printf(" -> ");
		temp = temp->next;
	}
	temp = stack_b;
	printf("\n");
	while (temp)
	{
		printf("(%d)", *(int *)(temp->content));
		printf(" -> ");
		temp = temp->next;
	}
	printf("\n");
	
	ft_lstclear(&stack_a, delelements);
	ft_lstclear(&stack_b, delelements);
	clear_array(arr, delelements);
}
// for (size_t i = 0; i < arr->number_of_elememts; i++)
// {
// 	printf("%s\n", (char *)get_element(arr, i));
// }
