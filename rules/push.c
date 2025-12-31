#include "linked_list/linked_list.h"

void	ft_push(t_list **dest, t_list *src)
{
	if (!(*src))
		return ;
	ft_lstadd_front(dest, src);
}