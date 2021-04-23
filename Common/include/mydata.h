#ifndef _MYDATA_H
// static int static_array[] = {1,8,4,5100,200,45,67,89,34,54,54,32,100,0,-1};
// static int array_len = 15;

//将数组和数组长度绑定
//int long
typedef struct int_data{
    int *darray;
    size_t len;
}int_l;

typedef struct charp_data{
    char *darray;
    size_t len;
} charp_l;

//int type   singal link-list
typedef struct int_sll_node{
    int data;
    struct int_sll_node *next;
}int_sll_node;

//link-list 整体
typedef struct int_sll{
    int_sll_node *node;
    int len;
}int_sll;
//circual linking-list

typedef int_sll_node cll_node_int_t;
typedef int_sll cll_int_t;


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


int_l *darray_init(int_l*,size_t);
int_l *darray_add_len(int_l *darray,size_t add_len);
int_l *darray_random_data(int_l *);
void darray_free(int_l darray);
int_l *darray_insert(int_l *data,int location,int add_number);
void darray_delete(int_l *data,int location);


int_sll *sll_init(int_sll *sll,int len);
int_sll* sll_traverse(int_sll *sll,void (*operate)(int_sll_node *));
int_sll *sll_random_data(int_sll *sll);

void static sll_operate_print(int_sll_node *node);
void static sll_operate_free(int_sll_node *node);
int_sll *sll_insert(int_sll *sll,int location,int data);
int_sll *sll_delete(int_sll *sll,int location);
void sll_free(int_sll *sll);

typedef void (*dll_op_ft)(dll_t *dll,dll_node_t *node,int i);
dll_t *dll_init(dll_t *dll,int len);
dll_t *dll_traverse(dll_t *dll,dll_op_ft operate);
dll_t *dll_rtraverse(dll_t *dll,dll_op_ft operate);
dll_t *dll_random_data(dll_t *dll);
dll_t *dll_insert(dll_t *dll,int location,data_t *data);
dll_t *dll_delete(dll_t *dll,size_t location);
void static _dll_op_random_data(dll_t *dll,dll_node_t *node,int i);

void dll_op_print(dll_t *dll,dll_node_t *node,int i);

#define _MYDATA_H
#endif