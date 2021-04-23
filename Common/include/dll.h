#ifndef _DARRAY_H_
#include <stddef.h>

//double link-list
typedef struct dll_node{
    void *data;
    struct dll_node* next;
    struct dll_node* pre;
}dll_node_t;

typedef struct dll{
    dll_node_t *head;
    dll_node_t *tail;
    int len;
}dll_t;
//double circle link-list
typedef dll_node_t dcll_node_t;
typedef dll_t dcll_t;

typedef struct {
    int int_data;
    void *next;
}data_t;
typedef void (*dll_op_ft)(dll_t *dll,dll_node_t *node,int i);
dll_t *dll_init(dll_t *dll,int len);
dll_t *dll_traverse(dll_t *dll,dll_op_ft operate);
dll_t *dll_rtraverse(dll_t *dll,dll_op_ft operate);
dll_t *dll_random_data(dll_t *dll);
dll_t *dll_insert(dll_t *dll,int location,data_t *data);
dll_t *dll_delete(dll_t *dll,size_t location);
void static _dll_op_random_data(dll_t *dll,dll_node_t *node,int i);
void dll_op_print(dll_t *dll,dll_node_t *node,int i);


#define _LINKLIST_H

#endif