#include <stdio.h>
#include "token.h"

void sliceString(char *string, char *destination, int start, int end) {
    for (int i = 0; i < end - start; ++i) {
        destination[i] = string[start + i];
    }
}

// counts how many same type tokens are
// -1: there is no that type     other than -1: the index it is first occurence
int tokenTypeCounter(TokenType type, Token tokens[], int size) {
    int count = 0;
    int index = -1;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType == type) {
            count++;
            index = i;
        }
    }
    if (count==1)
    {
        /* code */
    }
    
    return count;
}

// counts how many parentheses are (output: 1 is error / 0 is no error)
int parCheck(Token tokens[], int size) {
    int count = 0;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType == PARANTHESIS_OPENING) {
            count++;
        } else if(tokens[i].tokenType == PARANTHESIS_CLOSING) {
            count--;
        }
        if (count<0) {
            return 1;
        }
    }
    //printf("%d", count);
    if (count!=0) {
        return 1;
    }
    for(int i=0 ; i<size - 1 ; ++i) {
        if ((tokens[i].tokenType == FUNCTION_XOR || tokens[i].tokenType == FUNCTION_LS ||
            tokens[i].tokenType == FUNCTION_RS || tokens[i].tokenType == FUNCTION_LR ||
            tokens[i].tokenType == FUNCTION_RR || tokens[i].tokenType == FUNCTION_NOT) & tokens[i+1].tokenType != PARANTHESIS_OPENING)
        {
            return 1;
        }
        
    }

    //printf("end %d", count);
    return 0;
}

// there is at least one sequential
int isSequential(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; i < size1; ++i) {
            if (tokens[i].tokenType == tokenTypes1[j]) {
                for (int k = 0; i < size2; ++i) {
                    if (tokens[i+1].tokenType == tokenTypes2[k]) {
                        return 1;
                    }
                }  
            }
        }
    }
    return 0;
}

int isSequential(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2) {
    for (int i = 0; i < size - 1; ++i) {
        if (tokens[i].tokenType == tokenType1) {
            if (tokens[i+1].tokenType == tokenType2) {
                return 1;
            }
        }  
    }
    return 0;
    
}

// there is at least one not sequential
int isNotSequential(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; i < size1; ++i) {
            if (tokens[i].tokenType == tokenTypes1[j]) {
                for (int k = 0; i < size2; ++i) {
                    if (tokens[i+1].tokenType != tokenTypes2[k]) {
                        return 1;
                    }
                }  
            }
        }
    }
    return 0;
}

int isNotSequential(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2) {
    for (int i = 0; i < size - 1; ++i) {
        if (tokens[i].tokenType == tokenType1) {
            if (tokens[i+1].tokenType != tokenType2) {
                return 1;
            }
        }  
    }
    return 0;
}