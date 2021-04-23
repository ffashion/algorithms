#include "stack.h"
int main(int argc, char const *argv[]){
    stack_sll_t init;

    //default len 100
    stack_sll_init(&init,1);


    stack_sll_push(&init,3);

    // stack_push(&init,3);
    // stack_push(&init,3);
    // stack_push(&init,3);
    // stack_push(&init,3);
    // stack_push(&init,3);
    // stack_push(&init,3);
    // for (size_t i = 0; i <100000; i++){
    //     stack_push(&init,i);
    // }

    // for (size_t i = 0; i <100000; i++)
    // {
    //     stack_pop(&init);
    // }
    // stack_pop(&init);

    stack_sll_traverse(&init,stack_sll_op_print);
    // stack_dar_init

    return 0;
}
