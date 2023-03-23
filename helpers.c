#include "token.h"
void sliceString(char *string, char *destination, int start, int end) {
    for (int i = 0; i < end - start; ++i) {
        destination[i] = string[start + i];
    }
}

// counts how many same type tokens are
int tokenTypeCounter(TokenType type, Token tokens[], int size) {
    int count = 0;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType = type) {
            count++;
        }
    }
    return count;
}

// counts how many parentheses are (output: 1 is error / 0 is no error)
int parCheck(Token tokens[], int size) {
    int count = 0;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType = PARANTHESIS_OPENING) {
            count++;
        } else if(tokens[i].tokenType = PARANTHESIS_CLOSING) {
            count--;
        }
        if (count<0) {
            return 1;
        }
    }
    if (count=!0) {
        return 1;
    }
    return 0;
}