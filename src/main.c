#include "main.h"

int main(int argc,char* argv[]){
    if(argc < 2){
           printf(".may fatal error: no input files");
        exit(0);
    };

    if(strstr(argv[1],".may") == 0){
           printf("may error: %s:No such file or directory",argv[1]);
        exit(0);
    };


    char equ[N] = {'\0'};//масив для рiвняння
    parcer_main(equ,argv[1]);
    double result = calculus_prn(equ);
    printf("%g\n",result);

    return 0;
};

/*
 *добавити
 *щоб можно було так 
 *euq{
 *  x*x
 *}
 *let{n = 10}
 *let{x = 2}
 *sum{from(0){x}to(n)}
 *що значить додати 10 разiв два
 *добавити обчислення квадратного рiвняння
 */