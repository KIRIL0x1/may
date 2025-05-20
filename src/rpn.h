//revers polish notation

#ifndef RPN_h
#define RPN_h

int priority(int c);
bool is_operator(char buff);
bool is_numeric(char c);
void revers_polish_notation(char* buff);

#endif