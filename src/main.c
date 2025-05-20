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

    char expr[N] = {'\0'};
    char buff[N] = {'\0'};//парсерене рiвняння
    double result = 0;

    parcer_main(expr,buff,argv[1]);
    result = calculus_prn(buff);
    printf("%g\n",result);

    return 0;
};