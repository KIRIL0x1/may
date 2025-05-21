#ifndef PARCER_H
#define PARCER_H

typedef struct var{
    double val;
    char name;
}var;

void nospace(char *str);

void equ_perc(char* expr,var* t,char* buff);

void parcer_main(char* buff,char* file_name);

#endif