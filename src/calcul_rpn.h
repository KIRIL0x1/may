#ifndef CALCUL_RPN_H
#define CALCUL_RPN_H



/*size1 це довжина 
 *size2 ширина
 *sizetype це розмiр одного елемента
 */
void** doublemalloc(int size1,int size2,int sizetype);
//size це ширина
void doublefree(void** buff,int size);
char** one_to_double_arr(char* vbuff,int* count);
double calculus_prn(char* vbuff);

bool is_numeric_arr(char* buff);
bool is_operator_arr(char* buff);


#endif