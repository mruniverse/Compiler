#include "parser/parser.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    extern string input;
    extern char lookahead;

    input = "24+54";
    lookahead = nextToken();
    expr();
}
