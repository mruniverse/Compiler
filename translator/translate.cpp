#include "translate.hpp"
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>

using namespace std;

string input;
char lookahead;
int pos = 0;

void print(char c){
    printf("%c", c);
}

char nextToken(){
    if(pos < input.length()){
        return input[pos++];
    }
    else{
        return EOF;
    }
}

void term(){
    if (isalpha(lookahead)){         //var ================================
        print(lookahead);
        match(lookahead);
    }
    else if(isdigit(lookahead)) {    //number =============================
        int a = 0;

        do{
            a = 10*a+atoi(&lookahead);
            print(lookahead);
            lookahead = nextToken();
        }while(isdigit(lookahead));

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
        match('+'); term(); print('+'); rest();
    }
    else if (lookahead == '-'){
        match('-'); term(); print('-'); rest();
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
