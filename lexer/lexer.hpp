#define NUMBER 256
#define VARIABLE 257
#define OPERATOR 258

void token_number(int i);
void token_operator(char c);
void token_variable(char c);
void print_token(struct token t);

struct token{
    int type;
    int value;
};
