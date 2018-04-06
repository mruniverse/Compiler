#include "translator/translate.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string input = "24+54";
    char lookahead = nextToken();
    expr();
}
