#include "main.h"

static void setdata(stack* n,void* data,unsigned int size){
    if(n->data) free(n->data);
    n->data = malloc(size);
    memcpy(n->data,data,size);
};

stack* push(stack* n,void* data,int size){
    stack* t = malloc(sizeof(stack));
    t->data = NULL;
    setdata(t,data,size);
    t->next = n;
    return t;
};

stack* pop(stack* n){
    if(!n) return NULL;
    if(n->data) free(n->data);
    stack* t = n->next;
    free(n);
    return t;
};


