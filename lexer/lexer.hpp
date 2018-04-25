#define NUMBER 256
#define VARIABLE 257
#define OPERATOR 258

void token_number(int);
void token_operator(char);
void token_variable(char);
void print_token(struct token);

extern char lookahead;

struct token{
    int type;
    int value;
};

// extern char lookahead;
