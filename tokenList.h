struct Node {
    Token token;
    struct Node *next;
    struct Node *prev;
};

typedef struct TokenList {
    struct Node *head;
    struct Node *tail;
    int size;
}TokenList;

Token peekTop(TokenList *tokenList);

Token popTop(TokenList *tokenList);

Token popBottom(TokenList *tokenList);

void push(TokenList *tokenList, Token token);

