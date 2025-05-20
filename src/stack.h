#ifndef STACK_H
#define STACK_H

typedef struct stack{
    void* data;
    struct stack* next;
}stack;

stack* push(stack* n,void* data,int size);
stack* pop(stack* n);

#endif
