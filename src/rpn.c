// revers polish notation
#include "main.h"

int priority(int c){
    if (!c)
        return 0;
    switch (c){
    case '+':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '-':
        return 1;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return 0;
        break;
    };
};

bool is_operator(char buff){
    if (buff == '+' || buff == '*' || buff == '-' || buff == '/' || buff == '^'){
        return true;
    };
    return false;
};

bool is_numeric(char c){
    return (('0' <=  c) && (c <= '9')) || (c == '.');
};

void revers_polish_notation(char* buff){
    stack *n = NULL;
    
    int size = strlen(buff);
    char* buff1 = calloc(size*2,sizeof(char));
    int k = 0;

    for (int i = 0; i < size; i++){    
        if (is_numeric(buff[i]) || (buff[i] == '-' && i == 0) || (i > 0 && buff[i-1] == '(' && buff[i] == '-')){            
            while(is_numeric(buff[i]) || (buff[i] == '-' && i == 0) || (i > 0 && buff[i-1] == '(' && buff[i] == '-'))
                buff1[k++] = buff[i++];
            buff1[k++] = ' ';
            i--;
        };

        if (buff[i] == '('){
            n = push(n, &buff[i], sizeof(buff[i]));
        };
    
        if (buff[i] == ')'){
            while (*(char*)n->data != '('){
                buff1[k++] = *(char*)n->data;
                n = pop(n);
                buff1[k++] = ' ';
            };
            if (*(char*)n->data == '('){
                n = pop(n);
            };
        };
    
        if (is_operator(buff[i])){
            while (n != NULL && priority(*(char*)n->data) >= priority(buff[i])){
                buff1[k++] = *(char*)n->data;
                n = pop(n);
                buff1[k++] = ' ';
            };
            n = push(n, &buff[i], sizeof(buff[i]));
        };
    };

    while (n != NULL){
        buff1[k++] = *(char*)n->data;
        n = pop(n);
        buff1[k++] = ' ';
    };

    buff1[k] = '\0';
    strcpy(buff, buff1);
};