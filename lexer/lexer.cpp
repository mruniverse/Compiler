#include "lexer.hpp"
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct token t;

void token_number(int i){
    t.type = NUMBER;
    t.value = i;
}

void token_operator(char c){
    t.type = OPERATOR;
    t.value = c;
}

void token_variable(char c){
    t.type = VARIABLE;
    t.value = c;
}

void print_token(struct token t){
    if (t.type == VARIABLE || t.type == OPERATOR){
        printf("\n%d | %c \n", t.type, t.value);
    }
    else{
        printf("\n%d | %d \n", t.type, t.value);
    }
}
