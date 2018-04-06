#define NUMBER 256
#define SYMBOL 257

void token_number(int i);
void token_symbol(char c);
void print_token(struct token t);

struct token{
    int type;
    int value;
};
