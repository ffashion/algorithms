#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "darray.h"
//get a dynamic array
/**
 *  init_len : init len for dynamic array
*/
darray_t *darray_init(darray_t *init,size_t len){
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
darray_t* darray_add_len(darray_t *darray,size_t add_len){
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


darray_t *darray_random_data(darray_t *darray){
    srand(time(NULL));
    for (size_t i = 0; i <= darray->len-1; i++){
        //设置一个新的种子
        darray->darray[i] = rand() % 1000 - 500;
    }
    return darray;
}

darray_t *darray_insert(darray_t *data,int location,int add_number){
    darray_add_len(data,1);
    for (size_t i = data->len -1; i >= location; i--){
        data->darray[i+1] = data->darray[i];
    }
    data->darray[location] = add_number;
    return data;
}

darray_t * darray_delete(darray_t *data,int location){
    for (size_t i = location; i <= data->len-1; i++){
        data->darray[i] = data->darray[i+1];
    }
    data->len--;
    return data;
    
}

//free
void darray_free(darray_t darray){
    free(darray.darray);
}

