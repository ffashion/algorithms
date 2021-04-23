#ifndef _DARRAY_H_
#include <stddef.h>
//将数组和数组长度绑定
//int long
typedef int darray_node_t;
typedef struct{
    //head address 
    darray_node_t *darray;
    size_t len;
}darray_t;

darray_t *darray_init(darray_t* init,size_t init_len);
darray_t*darray_add_len(darray_t*darray,size_t add_len);
darray_t*darray_random_data(darray_t* darray);
void darray_free(darray_t darray);
darray_t*darray_insert(darray_t*data,int location,int add_number);
darray_t *darray_delete(darray_t*data,int location);


#define _LINKLIST_H

#endif