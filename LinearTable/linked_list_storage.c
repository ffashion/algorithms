#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sll.h"


int main(int argc, char const *argv[])
{   
    sll_t data;
    sll_init(&data,10);
    // sll_traverse(&data);
    sll_random_data(&data);
    // sll_traverse(&data,sll_operate_print);
    // sll_insert(&data,10,9);
    // sll_traverse(&data,sll_operate_print);
    printf("%d\n",data.len);
    sll_delete(&data,9);
    printf("%d\n",data.len);
    // sll_traverse(&data,sll_operate_print);
    return 0;
}


