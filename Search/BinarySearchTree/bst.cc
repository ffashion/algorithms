#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
/**
 * @brief   
 * |   4 
 *   /   \
 *  3     8    insert 9
 *  
 * 
 * 
 */

typedef struct bst_node {
    struct bst_node *left;
    struct bst_node *right;
    int data;
}bst_node_t;

typedef struct bst {
    bst_node_t *root;
}bst_t;


int bst_insert(bst_t *bst, int data) {
    if (!bst) 
        return -1;
    if (!bst->root) {
        bst->root = (bst_node_t *)malloc(sizeof(bst_node_t));
        
        if (!bst->root)
            return -1;
        
        bst->root->data = data;
        return 0;
    }
    bst_node_t *node = bst->root;
    bst_node_t *new_node = (bst_node_t *)malloc(sizeof(bst_node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    for (; node ;) {
        if (data > node->data) {
            if (node->right) 
                node = node->right;
            else {
                node->right = new_node;
                break;
            }
        }
        else {
            if (node->left) 
                node = node->left;
            else {
                node->left = new_node;
                break;
            }
        }      
    }
    return 0;
}

//
static int delete_node(bst_node_t **node) {

    bst_node_t *q,*s;
    if (!(*node)->right) {
        q = *node;
        *node = (*node)->left;
        free(q);
    }else if (!(*node)->left) {
        q = *node;
        *node = (*node)->right;
        free(q);
    }else {
        q = *node;
        // s = 
    }


    return 0;
}

int bst_delete(bst_t *bst, int data) {
    if (!bst || !bst->root) 
        return -1;
    bst_node_t *node = bst->root;

    for (;node;) {
        if(data == node->data)
            return delete_node(&node);
        else if(data > node->data) 
            node = node->left;
        else if(data < node->data) 
            node = node->right;
    }
    return -1;
}
bst_node_t *bst_search(bst_t *bst, int data) {
    if (!bst || !bst->root) 
        return NULL;

    bst_node_t *node = bst->root;

    for (;node;) {
        if (data == node->data)
            return node;
        else if (data > node->data)
            node = node->right;
        else if (data < node->data) 
            node = node->left;
    }
    return NULL;
}

bst_t *bst_new(){
    bst_t *ret = (bst_t *)malloc(sizeof(bst_t));
    if (!ret) 
        return NULL;
    ret->root = NULL;
    return ret;
}

int bst_free(bst_t *bst) {

    return 1;
}

int bst_middile_reverse(bst_t *bst) {
    if (!bst || !bst->root) 
        return -1;
    
    bst_node_t *node = bst->root;
    
    queue<bst_node_t *> q ;
    //push root to the queue
    q.push(node);

    for (;!q.empty();)  {
        node = q.front();  q.pop();
        if (node) {
            printf("%d ",node->data);
            q.push(node->left);
            q.push(node->right);
        }
    }
    return 1;

}

//ToDo : balance a BST

int main(int argc, char const *argv[])
{
    bst_t *bst =  bst_new();
    bst_node_t *node  = NULL;
    
    for (int i =10; i<=20; i++) {
        bst_insert(bst,i);
    }
    for (int i =50; i<=60; i++) {
        bst_insert(bst,i);
    }
    for (int i =70; i<=90; i++) {
        bst_insert(bst,i);
    }

    for (int i =0; i<=9; i++) {
        bst_insert(bst,i);
    }
    
    node = bst_search(bst,20);
    if (node) 
        printf("node->data :%d\n",node->data);

    bst_middile_reverse(bst);
    return 0;
}
