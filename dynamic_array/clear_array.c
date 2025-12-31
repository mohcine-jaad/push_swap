#include "dynamic_array.h"

void clear_array(t_array *obj, void (*delelements)(void *))
{
    size_t i;

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