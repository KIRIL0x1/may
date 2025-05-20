#ifndef PARCER_H
#define PARCER_H

typedef struct zmin{
    double val;
    char name;
}zmin;

void nospace(char *str);

void riv_perc(char* expr,zmin* t,char* buff);

void parcer_main(char* expr,char* buff,char* file_name);

#endif