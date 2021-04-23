#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "mydata.h"
//get a dynamic array
/**
 *  init_len : init len for dynamic array
*/
int_l *darray_init(int_l *init,size_t len){
    //if init is legal 
    if(init == NULL){
        printf("init is illegal");
        return NULL;
    }

    init->len = len;
    //default  len is ten
    if(init->len == 0){
        init->len = 10;
    }
    init->darray = (int *)malloc(sizeof(int) *init->len);
    memset(init->darray,0,sizeof(int)*init->len);
    
    return init;
}

//add dynamic array len
//default add double if add_len==0
int_l* darray_add_len(int_l *darray,size_t add_len){
    //if len or daarray is illegal
    if(darray == NULL){
        printf("the darray is illegal");
        return NULL;
    }

    //add array len 
    if(add_len == 0){
        darray->darray = realloc(darray->darray,sizeof(int) *darray->len*2);
        //set default value
        memset(darray->darray+darray->len,0,sizeof(int) *darray->len);
        //set new len
        darray->len = darray->len * 2;

    }else{
        darray->darray = realloc(darray->darray,sizeof(int) *(darray->len+add_len));
        //set default value
        memset(darray->darray+darray->len,0,sizeof(int) *add_len);
        //set new len
        darray->len = darray->len + add_len;
    }
    
    //return 
    return darray;
}


int_l *darray_random_data(int_l *darray){
    srand(time(NULL));
    for (size_t i = 0; i <= darray->len-1; i++){
        //设置一个新的种子
        darray->darray[i] = rand() % 1000 - 500;
    }
    return darray;
}

int_l *darray_insert(int_l *data,int location,int add_number){
    darray_add_len(data,1);
    for (size_t i = data->len -1; i >= location; i--){
        data->darray[i+1] = data->darray[i];
    }
    data->darray[location] = add_number;
    return data;
}

void darray_delete(int_l *data,int location){
    for (size_t i = location; i <= data->len-1; i++){
        data->darray[i] = data->darray[i+1];
    }
    data->len--;
    
}

//free
void darray_free(int_l darray){
    free(darray.darray);
}


int_sll *sll_init(int_sll *sll,int len){
    int_sll_node *node = NULL;
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
            sll->node = (int_sll_node*)malloc(sizeof(int_sll_node));
            node = sll->node;
        }

        //set node  data value 
        node->data= 0;
        //set node  next value
        if(i != sll->len -1) {
            node->next = (int_sll_node*)malloc(sizeof(int_sll_node));
        }else{
            //the last node 
            node->next =NULL;
        }
        //next switch to next node
        node = node->next;
    }


    
    return sll;
}




int_sll* sll_traverse(int_sll *sll,void (*operate)(int_sll_node *node)){
    //judge wheather sll is legal or not
    if(sll == NULL){
        printf("sll is invalid");
        return NULL;
    }
    //set first node 
    int_sll_node *node = NULL;
    node = sll->node;

    //traverse
    for (size_t i = 0; i <=sll->len-1; i++){

        operate(node);
        node = node->next;
    }
    
    return sll;
}

int_sll *sll_random_data(int_sll *sll){
    // sll if illegal 
    if(sll == NULL){
        printf("sll is illegal");
    }

    //set random value for every node  -1000 到1000
    int_sll_node *node = sll->node;
    srand(time(NULL));
    for (size_t i = 0; i <=sll->len-1; i++){
        node->data = rand() % 2000 - 1000;
        node = node->next;
    }
    
    return sll;
}

//location :0  ~ len
//插入到节点的前面
int_sll *sll_insert(int_sll *sll,int location,int data){
    //judge wheather sll is legal or not
    if(sll == NULL){
        printf("sll is invalid");
        return NULL;
    }

    //create empty node  and give data
    int_sll_node *empty_node = (int_sll_node *)malloc(sizeof(int_sll_node));
    empty_node->data = data;

    //insert node  插入到节点的前面
    int_sll_node *node = NULL;
    node = sll->node;
    for (size_t i = 0; i <= location; i++){
        //if is the first node 
        if(location == 0){
            empty_node->next = node;
            node = empty_node;
            sll->node = node;
            break;
        }
        //other node(include the last node)
       //location 的前一个节点
        if(i == location -1){
            empty_node->next = node->next;
            node->next = empty_node;
            break;
        }
        node = node->next;
    }
    
    // add len
    sll->len ++;

    return sll;
}
// location 0 ~ len-1
int_sll *sll_delete(int_sll *sll,int location){
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
    int_sll_node *node =NULL;
    node = sll->node;

    int_sll_node *for_free_tmp = NULL;
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
            break;
        }

        
        //switch node
        node = node->next;
    }

    //len -1
    sll->len--;


    return sll;
}

void static  sll_operate_print(int_sll_node *node){
    if(node != NULL){
        printf("%d->",node->data);
    }
    if(node->next == NULL){
        printf("NULL\n");
    }
}
void static sll_operate_free(int_sll_node *node){
    free(node);
}
void sll_free(int_sll *sll){

    sll_traverse(sll,sll_operate_free);
}


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
void static dll_op_free(dll_t *dll,dll_node_t *node,int i){

}

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
void static _dll_op_insert(dll_t *dll,dll_node_t *node,int i){
    //first node 
    if(i == 0){
        node->pre = NULL;
        node->next = dll->head;
        dll->head = node;
    }
    //other node 
    if(i != dll->len -1 && i != 0){
            
    }
    //last node 

    //add len
}
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
        //last node  分情况讨论 是插入在最后一个节点之前还是之后 (如果单链表 必须要分情况讨论 否则到插入到最后一个节点后面的时候node的值为NULL,这里没有分情况讨论)
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
