#include "token.h"
#include "tokenList.h"
#include <stdlib.h>
#include <stdio.h>

// assign memory to a new token list
TokenList *createTokenList() {
    TokenList *newList = malloc(sizeof(TokenList));
    newList->size = 0;
}

// return the top element of the list
Token peekTop(TokenList *tokenList) {
    return tokenList->tail->token;
}

// pop the top element on the list and return it
Token popTop(TokenList *tokenList) {
    tokenList->size--;
    struct Node *oldTail = tokenList->tail;
    tokenList->tail = oldTail->prev;
    Token oldTailToken = oldTail->token;
    free(oldTail);
    return oldTailToken;
}

// pop the bottom element on the list and return it
Token popBottom(TokenList *tokenList) {
    tokenList->size--;
    struct Node *oldHead = tokenList->head;
    tokenList->head = oldHead->next;
    Token oldHeadToken = oldHead->token;
    free(oldHead);
    return  oldHeadToken;
}

// push a token on top of the list
void push(TokenList *tokenList, Token token) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->token = token;
    newNode->prev = tokenList->tail;
    if(tokenList->size == 0) {
        tokenList->head = newNode;
        tokenList->tail = newNode;
    }
    else
    {   
    tokenList->tail->next = newNode;
    tokenList->tail = newNode;
    }
   
    tokenList->size++;
}