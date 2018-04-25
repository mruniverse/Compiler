#include "parser.hpp"
#include "../lexer/lexer.hpp"
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

char lookahead;
// string postfix;
// struct token t;

void term(){
    if (isalpha(lookahead)){         //var ==================================
        printf("%c ", lookahead);
        token_variable(lookahead);
        print_token(t);
        match(lookahead);
    }
    else if(isdigit(lookahead)) {    //number ===============================
        //Identify more than one number =====================================
        int a = 0;
        do{
            a = 10*a+atoi(&lookahead);
            match(lookahead);
        }while(isdigit(lookahead));
        printf("%d ", a);
        // postfix += to_string(a);
        //===================================================================
        token_number(a);
        print_token(t);
        // print(lookahead);
    }
    else{
        printf("Syntax error on term\n");
        exit(1);
    }
}

void rest(){
    if (lookahead == '+'){
        token_operator('+');
        print_token(t);

        match('+'); term(); printf("%c", '+'); rest();
    }
    else if (lookahead == '-'){
        token_operator('-');
        print_token(t);

        match('-'); term(); printf("%c", '-'); rest();
    }
    else if (lookahead == '='){
        token_operator('=');
        print_token(t);

        match('='); term(); printf("%c", '='); rest();
    }
    else if (lookahead == EOF){
        // printf("\n%s\n", postfix);
        printf("\nSuccess.\n");
        pos = 0;
    }
    else {
        printf("Syntax error on x\n");
        exit(1);
    }
}

void expr(){
    lookahead = nextToken();
    term(); rest();
}
