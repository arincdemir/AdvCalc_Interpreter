#include "token.h"
#include "tokenList.h"
#include <stdlib.h>

TokenList *createTokenList() {
    TokenList *newList = malloc(sizeof(TokenList));
    newList->size = 0;
}

Token peekTop(TokenList *tokenList) {
    return tokenList->tail->token;
}

Token popTop(TokenList *tokenList) {
    tokenList->size--;
    struct Node *oldTail = tokenList->tail;
    tokenList->tail = oldTail->prev;
    Token oldTailToken = oldTail->token;
    free(oldTail);
    return oldTailToken;
}

Token popBottom(TokenList *tokenList) {
    tokenList->size--;
    struct Node *oldHead = tokenList->head;
    tokenList->head = oldHead->next;
    Token oldHeadToken = oldHead->token;
    free(oldHead);
    return  oldHeadToken;
}

void push(TokenList *tokenList, Token token) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->token = token;
    newNode->prev = tokenList->tail;
    tokenList->tail->next = newNode;
    tokenList->tail = newNode;
    tokenList->size++;
}