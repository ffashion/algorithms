#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "darray.h"
int main(int argc, char const *argv[])
{

    darray_t data;
    darray_init(&data,10);
    // darray_random_data(&data);
    darray_insert(&data,3,1);
    for (size_t i = 0; i <= data.len-1; i++){
        printf("%d ",data.darray[i]);
    }
    printf("\n");
    darray_delete(&data,3);
    for (size_t i = 0; i <= data.len-1; i++){
        printf("%d ",data.darray[i]);
    }

    darray_free(data);
    return 0;
}
