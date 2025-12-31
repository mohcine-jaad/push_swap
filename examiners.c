#include "push_swap.h"
#include "dynamic_array/dynamic_array.h"
#include "linked_list/linked_list.h"

int	find_space(char *str)
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
	while(*str)
    {
        if(*str < '0' || *str > '9')
            return (1);
        str++;
    }
	return (0);
}

int isduplicated(t_list *list)
{
	t_list *tmp;

	while (list->next->next)
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
	return(0);
}