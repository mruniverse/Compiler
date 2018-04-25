#include <string>
#include <iostream>

extern std:: string input;
extern char lookahead;
extern struct token t;
extern int pos;

extern void match(char);

void term();
void rest();
void expr();
void print(char);
char nextToken();
