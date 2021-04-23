#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "sll.h"
sll_t *sll_init(sll_t *sll,int len){
    sll_node_t *node = NULL;
    //  judge whether sll is legal or not
    if(sll == NULL){
        printf("init sll is illegal");
    }

    //set length :default lengh equals to 100
    if(len == 0){
        sll->len = 100;
    }else{
        sll->len = len;
    }
    //create node && set  all node default value equals to zero
    for (size_t i = 0; i <= sll->len-1; i++){
        //set first node 
        if(i == 0){
            sll->node = (sll_node_t*)malloc(sizeof(sll_node_t));
            node = sll->node;
        }
        //set node  data value 
        node->data= 0;
        //set node  next value
        if(i != sll->len -1) {
            node->next = (sll_node_t*)malloc(sizeof(sll_node_t));
        }else{
            //the last node 
            node->next =NULL;
            // set tail 
            sll->tail = node;
        }
        //next switch to next node
        node = node->next;
    }


    
    return sll;
}

sll_t* sll_traverse(sll_t *sll,void (*operate)(sll_node_t *node)){
    //judge wheather sll is legal or not
    if(sll == NULL){
        printf("sll is invalid");
        return NULL;
    }
    //set first node 
    sll_node_t *node = NULL;
    node = sll->node;

    //traverse
    for (size_t i = 0; i <=sll->len-1; i++){

        operate(node);
        node = node->next;
    }
    
    return sll;
}

sll_t *sll_random_data(sll_t *sll){
    // sll if illegal 
    if(sll == NULL){
        printf("sll is illegal");
    }

    //set random value for every node  -1000 到1000
    sll_node_t *node = sll->node;
    srand(time(NULL));
    for (size_t i = 0; i <=sll->len-1; i++){
        node->data = rand() % 2000 - 1000;
        node = node->next;
    }
    
    return sll;
}

sll_t *sll_data(sll_t *sll){

    return sll;
}

//location :0  ~ len
//插入到节点的前面
sll_t *sll_insert(sll_t *sll,int location,int data){
    //judge wheather sll is legal or not
    if(sll == NULL){
        printf("sll is invalid");
        return NULL;
    }

    //create empty node  and give data
    sll_node_t *new_node = (sll_node_t *)malloc(sizeof(sll_node_t));
    new_node->data = data;
    new_node->next = NULL;

    //insert node  插入到节点的前面
    sll_node_t *node = NULL;
    node = sll->node;

    //专为栈优化的 push_stack
    if(location == sll->len){
        //set new_node 
        sll->tail->next = new_node;

        //set tail
        sll->tail = new_node;

        sll->len ++;
        return sll;
    }

    for (size_t i = 0; i <= location; i++){
        //if is the first node 
        if(location == 0){
            new_node->next = node;
            node = new_node;
            sll->node = node;
            break;
        }
        //other node(include the last node)
       //location 的前一个节点
        if(i == location -1){

            new_node->next = node->next;
            node->next = new_node;
            break;
        }
        //other node 
        if(i == location -1 && sll->len -1 != location){
            //set new_node next
            new_node->next = node->next;

            //set pre
            node->next = new_node;
            
            break;

        }
        // the last node 
        // 分情况讨论 是插入在最后一个节点之前还是之后
        if(i == location-1 && sll->len -1 <= location){
            //插入到最后一个节点之前
            if(location == sll->len -1){
                //set new_node 
                new_node->next = node->next;
                //set pre node
                node->next = new_node;
            }   

            //插入到最后一个节点之后
            if(location == sll->len){
                // way 1
                //set new_node
                new_node->next = NULL;

                //set pre node
                node->next->next = new_node;

                //set tail
                sll->tail = new_node;
                
            }

            break;
        }
        //switch node
        node = node->next;
    }
    
    // add len
    sll->len ++;

    return sll;
}
// location 0 ~ len-1
sll_t *sll_delete(sll_t *sll,int location){
    //sll if ilegal 
    if(sll == NULL){
        printf("sll is illegal");
    }

    // if location is illegal
    if(location >= sll->len && location <= -1){
        printf("location is illegal");
        exit(-1);
    }

    //delete node && free node
    sll_node_t *node =NULL;
    node = sll->node;

    sll_node_t *for_free_tmp = NULL;

    // //专为栈优化的pop
    // if(location == sll->len -1){
    //     //del node 
       

    //     //set tail
        

    //     sll->len --;
    //     return sll;
    // }

    for (size_t i = 0; i <= location ; i++){
        //the first node 
        if(location == 0){
            sll->node = node->next;
            free(node);
            break;
        }
        //other node(not include last node)   location前一个节点
        if(i == location -1 && location != sll->len-1){
            //for free
            for_free_tmp = node->next;
            //del node 
            node->next = node->next->next;

            //free
            free(for_free_tmp);
            break;
            
        }
        //last node 
        if(i == location -1 && location == sll->len-1){
            
            free(node->next);
            
            node->next = NULL;

            //set tail 
            sll->tail = node;
            
            break;
        }

        
        //switch node
        node = node->next;
    }

    //len -1
    sll->len--;


    return sll;
}

// void static sll_operate_print(sll_node_t *node){
//     if(node != NULL){
//         printf("%d->",node->data);
//     }
//     if(node->next == NULL){
//         printf("NULL\n");
//     }
// }
// void static sll_operate_free(sll_node_t *node){
//     free(node);
// }

// void sll_free(sll_t *sll){

//     sll_traverse(sll,sll_operate_free);
// }
