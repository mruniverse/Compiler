#include <string>
#include <iostream>

extern std:: string input;
extern char lookahead;
extern struct token t;

void term();
void rest();
void expr();
void match(char);
void print(char);
char nextToken();
