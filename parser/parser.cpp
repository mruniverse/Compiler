#include "parser.hpp"
#include "../lexer/lexer.hpp"
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>

using namespace std;

int pos = 0;
string input;
char lookahead;
// struct token t;

char nextToken(){
    if(pos < input.length()){
        return input[pos++];
    }
    else{
        return EOF;
    }
}

void term(){
    if ('+' || '-'){         //var ==================================
        printf("%d",lookahead);
        // match(lookahead);
        lookahead = nextToken();

        token_symbol(lookahead);
        print_token(t);

    }
    else if(isdigit(lookahead)) {    //number ===============================
        //Identify more than one number =====================================
        int a = 0;
        do{
            a = 10*a+atoi(&lookahead);
            lookahead = nextToken();
        }while(isdigit(lookahead));
        printf("%d ", a);
        //===================================================================
        token_number(a);
        print_token(t);
        // print(lookahead);
        // match(lookahead);
    }
    else{
        printf("Syntax error on term\n");
        exit(1);
    }
}

void rest(){
    if (lookahead == '+'){
        match('+'); term(); printf("%c",'+'); rest();
    }
    else if (lookahead == '-'){
        match('-'); term(); printf("%c",'+'); rest();
    }
    else if (lookahead == EOF){
        printf("\nSuccess.\n");
    }
    else {
        printf("Syntax error on x\n");
        exit(1);
    }
}

void expr(){
    term(); rest();
}

void match(char c){
    if (lookahead == c){
        lookahead = nextToken();
    }
    else {
        printf("Match error");
    }
}
