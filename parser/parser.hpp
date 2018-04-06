#include <string>

void term();
void rest();
void expr();
void match(char);
void print(char);
char nextToken();

extern std:: string input;
extern char lookahead;
extern struct token t;
