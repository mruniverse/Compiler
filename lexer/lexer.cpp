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

void token_symbol(char c){
    t.type = SYMBOL
    t.value = c;
}

void print_token(struct token t){
    printf("\n%d | %d \n", t.type, t.value);
}
