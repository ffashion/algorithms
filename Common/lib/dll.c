#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dll.h"
dll_t *dll_init(dll_t *dll,int len){
    // if dll is illegal
    if(dll == NULL){
        printf("dll is illegal");
    }
    // set default len 
    if(len == 0){
        dll->len = 100;
    }else{
        dll->len = len;
    }

    dll_node_t *node = NULL;
    dll_node_t *tmp_node  = (dll_node_t *)malloc(sizeof(dll_node_t));
    //create node 
    // 第一次进入for 会执行2次malloc
    for (size_t i = 0; i <= len-1; i++){
        //first node
        if(i == 0){
            node = (dll_node_t *)malloc(sizeof(dll_node_t));
            dll->head = node;
            
            // set pre pointer 可写可不写
            node->pre = NULL;

            //save node 
            tmp_node = NULL;
        }
        //set default value
        node->data= malloc(sizeof(data_t));
        ((data_t *)node->data)->int_data = 0;
        
        //other node
        if(i != dll->len-1){
            node->pre = tmp_node;
            node->next = (dll_node_t *)malloc(sizeof(dll_node_t));
            tmp_node = node;
        }
        // last node 
        else{
            dll->tail = node;
            node->pre = tmp_node;
            node->next = NULL;
        }
        //switch node 
        node = node->next;
    }
    return dll;
}

dll_t *dll_traverse(dll_t *dll,dll_op_ft operate){
    //if dll is illegal 
    if(dll == NULL){
        printf("dll is illegal");
    }
    dll_node_t *node = NULL;
    node = dll->head;
    //traverse 
    for (size_t i = 0; i<=dll->len-1;i++){
        //operate
        operate(dll,node,i);
        //switch node 
        node = node->next;
    }
    return dll;
}

void dll_op_print(dll_t *dll,dll_node_t *node,int i){
    //if illegal or node is null 
    if(dll == NULL || node == NULL){
        printf("\nerror : %d处的node节点为NULL",i);
        fflush(NULL);
        exit(-1);
    }
    printf("%d->",((data_t *)(node->data))->int_data);
    if(i == dll->len-1){
        printf("\n");
    }
   
}

void static _dll_op_random_data(dll_t *dll,dll_node_t *node,int i){
    if(i == 0){
        srand(time(NULL));
    }
    ((data_t *)(node->data))->int_data = rand() % 2000 -1000;
}
// void static dll_op_free(dll_t *dll,dll_node_t *node,int i){

// }

dll_t *dll_random_data(dll_t *dll){
    dll_traverse(dll,_dll_op_random_data);
    return dll;
}

dll_t *dll_rtraverse(dll_t *dll,dll_op_ft operate){
    //if dll is illegal
    if(dll == NULL){
        printf("dll is illegal");
    }
    //r traverse 
    dll_node_t *node = NULL;
    node = dll->tail;

    for (size_t i = 0; i <= dll->len -1; i++){
        
        operate(dll,node,i);
        //switch node 
        node = node->pre;
    }
    return dll;
}
//0-dll->len
dll_node_t *list_for_each_entry(dll_t *dll){
    static dll_node_t *node = NULL;
    static int flag = 0;
    
    // first node
    if(node == NULL && flag == 0){
        node = dll->head;
        flag = 1;
    }
     //other node
    else{
        node = node->next;
        //循环dll->len次数 
        if(node == NULL){
            flag = 0;
        }
    }

    return node;
}
// void static _dll_op_insert(dll_t *dll,dll_node_t *node,int i){
//     //first node 
//     if(i == 0){
//         node->pre = NULL;
//         node->next = dll->head;
//         dll->head = node;
//     }
//     //other node 
//     if(i != dll->len -1 && i != 0){
            
//     }
//     //last node 

//     //add len
// }
//写insert的时候 要在最后一个节点的时候分类讨论。因为往前插入
//locaton :0- dll->len
dll_t *dll_insert(dll_t *dll,int location,data_t *data){
    //if dll is illegal 
    if(dll == NULL){
        printf("dll is illegal");
    }

    // if location is illegal
    if(location >= dll->len + 1 || location <= -1){
        printf("dll insert location is illegal");
        fflush(NULL);
        exit(-1);
    }
    // insert 
    dll_node_t * node = NULL;
    //malloc a new node 
    dll_node_t *new_node = (dll_node_t *)malloc(sizeof(dll_node_t));
    
    //set data 
    new_node->data = data;
    // printf("\n%d\n",data->int_data);
    
    node = dll->head;

    for (size_t i = 0; i<= location; i++){

        //inser first node 
        if(i == location && i== 0){
            new_node->next = dll->head;
            new_node->pre = NULL;
            dll->head = new_node;
            node->pre = new_node;
            break;
        }
        // other node
        else if(i == location && location <= dll->len -1 && i != 0){
            //set new node 
            new_node->next = node;
            new_node->pre = node->pre;
            //set pointer to new_node (pre and next)
            node->pre->next = new_node;
            node->pre = new_node;
            break;
        }
        //last node  建议分情况讨论 是插入在最后一个节点之前还是之后 (如果单链表 必须要分情况讨论 否则到插入到最后一个节点后面的时候node的值为NULL,这里没有分情况讨论)
        else if(i == location && location == dll->len){
            //reset node because node now is NULL
            node = dll->tail;

            //set new node 
            new_node->next = NULL;
            new_node->pre = node;
            //set pointer to new node
            
            node->next = new_node;
            //set dll
            dll->tail = new_node;
            break;

        }

        //switch node
        node= node->next;
    }
    //add len
    dll->len++;

    return dll;

}

//location 0 ~ len-1
dll_t *dll_delete(dll_t *dll,size_t location){
    //if dll is illegal
    if(dll == NULL){
        printf("dll is illegal");
        exit(-1);
    }
    //if location is illegal
    if(location >= (dll->len)){
        printf("dll delete location is illegal\n");
        fflush(NULL);
        exit(-1);
    }

    //delete node
    dll_node_t *node = NULL;
    node = dll->head;
    for (size_t i = 0; i <=location; i++){
        //first node
        if(i == location && i==0){
            //set dll
            dll->head = node->next;

            //del pointer to node
            node->next->pre = NULL;
            
            //free
            free(node);
            break;
        }
        //other node
        else if(i == location && location <= dll->len -2 && location != 0){
            //det pointer to node
            //set next 
            node->next->pre = node->pre;
            //set pre
            node->pre->next = node->next;

            //free 
            free(node);
            break;

        }
        //last node
        else if(i == location && location == dll->len -1){
            //set dll 
            dll->tail = node->pre;
            //set pre
            node->pre->next = NULL;

            free(node);
            break;
        }


        //switch node
        node = node->next;
    }
    
    //len--
    dll->len--;

    return dll;

}
