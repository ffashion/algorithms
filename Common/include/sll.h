#ifndef _DARRAY_H_

//int type   singal link-list
typedef struct sll_node_t{
    int data;
    struct sll_node_t *next;
}sll_node_t;

//link-list 整体
typedef struct sll_t{
    //head node 
    sll_node_t *node;
    sll_node_t *tail;
    int len;
}sll_t;
//circual linking-list

typedef sll_node_t cll_node_int_t;
typedef sll_t cll_int_t;

sll_t *sll_init(sll_t *sll,int len);
sll_t* sll_traverse(sll_t *sll,void (*operate)(sll_node_t *));
sll_t *sll_random_data(sll_t *sll);

// void static sll_operate_print(sll_node_t *node);
// void static sll_operate_free(sll_node_t *node);
sll_t *sll_insert(sll_t *sll,int location,int data);
sll_t *sll_delete(sll_t *sll,int location);
// void sll_free(sll_t *sll);



#define _LINKLIST_H

#endif