#include "main.h"

void nospace(char *str) {
    int i = 0, j = 0;
   
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];  
        };
        i++;
    };
    str[j] = '\0';  
};

void riv_perc(char* expr,zmin* t,char* buff){
    int k = 0;
    for(int i = 0; i < strlen(expr);i++){
        bool coun = false;
        for(int j = 0;j < 10;j++){
            if(expr[i] == t[j].name){
                char temp[30];
                sprintf(temp,"%g",t[j].val);
                for(int m = 0;m < strlen(temp);m++){    
                    buff[k++] = temp[m];
                };
                coun = true;
                break;
            };
        };
        if(!coun){
          buff[k++] = expr[i];
        };
    };

};

void parcer_main(char* expr,char* buff,char* file_name){
   
    FILE *file = fopen(file_name, "r");
    
    if (!file) {
        perror("ERROR");
        exit(1);
    };

    zmin t[10] = {'\0'};
    
    char line[N];
    
    int i = 0;

    while (fgets(line, sizeof(line), file)) {
        nospace(line);
        if (strncmp(line,"let{", 4) == 0) {
            sscanf(line,"let{%c=%lf}", &t[i].name, &t[i].val);
            i++;
        }else if (strncmp(line, "equ{", 4) == 0) {
            sscanf(line,"equ{%[^\n}]}", expr);
        };
    };

    fclose(file);
    riv_perc(expr,t,buff);    
};


/*
 *добавити
 *let{n = 10}
 *let{x = 2}
 *sum{
 *   from(0){
 *      x
 *   }to(n)
 * }
 *добавити обчислення квадратного рiвняння
 *що значить додати 10 разiв два
 */