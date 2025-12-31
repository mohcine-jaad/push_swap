#include "dynamic_array.h"

t_array* creat_array()
{
    t_array *arr;

    arr = malloc(sizeof(t_array));
    arr->current_size = 1025;
    arr->capacity = 2;
    arr->number_of_elememts = 0;
    arr->data = ft_calloc(sizeof(void *), (arr->current_size));
    return (arr);
}