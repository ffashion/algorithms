#ifndef _STACK_H_
#include <stddef.h>
#include "sll.h"
#include "darray.h"

typedef sll_t stack_sll_t;
typedef sll_node_t stack_sll_node_t;

typedef darray_t stack_dar_t;
typedef darray_node_t stack_dar_node_t;

stack_sll_t *stack_sll_init(stack_sll_t *init,size_t len);
stack_sll_t *stack_sll_push(stack_sll_t *stack,int data);
stack_sll_t *stack_sll_pop(stack_sll_t *stack);
stack_sll_t* stack_sll_traverse(stack_sll_t *stack,void (*operate)(stack_sll_node_t *));
void stack_sll_op_print(stack_sll_node_t *node);


stack_dar_t *stack_dar_init(stack_dar_t *init,size_t init_len);
stack_dar_t*stack_dar_add_len(stack_dar_t *darray,size_t add_len);
stack_dar_t*stack_dar_data(stack_dar_t* darray);
// void darray_free(darray_tdarray);
stack_dar_t*stack_dar_push(stack_dar_t *data,int add_number);
stack_dar_t *stack_dar_pop(stack_dar_t *data);





#define _STACK_H
#endif