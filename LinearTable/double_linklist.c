#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"

void plustwo(dll_t *dll,dll_node_t *node,int i){
    ((data_t *)node->data)->int_data +=2;
}
int main(int argc, char const *argv[])
{
    dll_t dll;
    data_t *data = malloc(sizeof(data_t));
    data->int_data = 2;
    dll_init(&dll,3);

    // dll_traverse(&dll,dll_op_print);
    dll_random_data(&dll);

    // dll_traverse(&dll,dll_op_print);
    
    // dll_rtraverse(&dll,dll_op_print);
    
    // dll_rtraverse(&dll,plustwo);
    // // dll_rtraverse(&dll,dll_op_print);

    // dll_traverse(&dll,dll_op_print);

    // printf("len :%d\n",dll.len);

    // dll_insert(&dll,3,data);
    
    dll_traverse(&dll,dll_op_print);
    // printf("len: %d\n",dll.len);


    dll_delete(&dll,2);
    dll_traverse(&dll,dll_op_print);

    // printf("%d\n",dll.len);

    return 0;
}
