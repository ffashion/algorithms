#include <stddef.h>
#include <stdio.h>
#include "stack.h"
stack_sll_t *stack_sll_init(stack_sll_t *init,size_t len){
    
    init = sll_init((sll_t *)init,len);

    return init;
}

stack_sll_t *stack_sll_push(stack_sll_t *stack,int data){
    sll_insert(stack,stack->len,data);
    return stack;
}

stack_sll_t *stack_sll_pop(stack_sll_t *stack){
    sll_delete(stack,stack->len-1);
    return stack;
}
void stack_sll_op_print(stack_sll_node_t *node){
    if(node != NULL){
        printf("%d->",node->data);
    }
    if(node->next == NULL){
        printf("NULL\n");
    }
}

stack_sll_t* stack_sll_traverse(stack_sll_t *stack,void (*operate)(stack_sll_node_t *)){
    sll_traverse(stack,operate);
    return stack;
}

stack_dar_t *stack_dar_init(stack_dar_t *init,size_t init_len){
    return darray_init(init,init_len);
}

stack_dar_t*stack_dar_add_len(stack_dar_t *darray,size_t add_len){
    return  darray_add_len(darray,add_len);
}


stack_dar_t*stack_dar_random_data(stack_dar_t* darray){
    return darray_random_data(darray);
}
stack_dar_t*stack_dar_push(stack_dar_t *stack,int add_number){
    
    return stack;
}


stack_dar_t *stack_dar_pop(stack_dar_t *stack){
    return stack;
}





