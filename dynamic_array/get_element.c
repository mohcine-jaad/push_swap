#include "dynamic_array.h"

void *get_element(t_array *arr, size_t index)
{
    if (index >= arr->current_size || index > arr->number_of_elememts)
        return NULL;
    return (arr->data[index]);
}