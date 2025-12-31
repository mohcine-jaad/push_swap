#include "dynamic_array.h"

void push_back(t_array *arr, void *element)
{
    if (arr->number_of_elememts == arr->current_size)
        resize_array(arr);
    arr->data[arr->number_of_elememts] = element;
    arr->number_of_elememts++;
}