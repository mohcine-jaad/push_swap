#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
#include "stdio.h"

typedef struct s_array
{
	size_t 	capacity;
	size_t 	current_size;
	size_t 	number_of_elememts;
	void	**data;
}		t_array;


void	clear_array(t_array *obj, void (*delelements)(void *));
t_array	*creat_array();
void	*get_element(t_array *arr, size_t index);
void	push_back(t_array *arr, void *element);
void	resize_array(t_array *arr);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif