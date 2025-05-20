#include "main.h"

/*size1 це довжина 
 *size2 ширина
 *sizetype це розмiр одного елемента
 */
void** doublemalloc(int size1,int size2,int sizetype){
    void** buff = malloc(size1*sizeof(void*));
    for(int i = 0;i < size1;i++){
        buff[i] = malloc(size2*sizetype);
    };
    return buff;
};

//size це ширина
void doublefree(void** buff,int size){    
    for(int i = 0;i < size;i++){
        free(buff[i]);
    };
    free(buff);    
};

char** one_to_double_arr(char* vbuff,int* count){
    //замiнити на двiйний динамiчний масив
    char** buff = (char**)doublemalloc(N,B,sizeof(char));

    int i = 0;
    char* token = strtok(vbuff," ");
    while(token != NULL){
        strcpy(buff[i],token);
        int y = strlen(buff[i]);
        buff[i][y] = ' ';
        buff[i][y+1] = '\0';
        token = strtok(NULL," "); 
        i++;
    };
    *count = i;
    return buff;
};

bool is_numeric_arr(char* buff){
    for(int i = 0;i < strlen(buff);i++){
        if(is_numeric(buff[i])){
            return true;
        };
    };
    return false;
};

bool is_operator_arr(char* buff){
    for(int i = 0;i < strlen(buff);i++){
        if(buff[i] == ' '){continue;};
        if(is_operator(buff[i])){continue;};
        if(!is_operator(buff[i])){return false;};
    };
    return true;
};

int oper(char* buff){
    for(int i = 0;i < strlen(buff);i++){
        switch (buff[i]){
            case '+':
                return '+';
                break;
            case '*':
                return '*';
                break;
            case '-':
                return '-';
                break;
            case '/':
                return '/';
                break;
            case '^':
                return '^';
                break;
            default:
                return -1;
        };
    };
    return -1;
};

double calculus_prn(char* vbuff){
    stack* n = NULL;
    revers_polish_notation(vbuff);

    int i = 0;
    char** buff = one_to_double_arr(vbuff,&i);
    double a = 0,b = 0,y = 0;    

    for(int j = 0;j < i;j++){
        if(is_numeric_arr(buff[j]))
            n = push(n,buff[j],strlen(buff[j])+1);
        if(is_operator_arr(buff[j]) && n != NULL){
            
            if(n != NULL){
                a = atof((char*)n->data);
                n = pop(n);
            };
        
            if(n != NULL){
                b = atof((char*)n->data);
                n = pop(n);
            };
            char c = oper(buff[j]);

            switch(c){
                case '+':
                    y = a + b; 
                    break;
                case '-':
                    y = b - a;
                    break;
                case '*':
                    y = a * b;
                    break;
                case '/':
                    y = b/a;
                    break;
            };
            char tmp[30];
            snprintf(tmp,sizeof(tmp), "%g", y);
            n = push(n,tmp,strlen(tmp)+1);
        }; 
        
    };
    while(n != NULL){
        n = pop(n);
    };

    doublefree((void**)buff,N);
    return y;
};
