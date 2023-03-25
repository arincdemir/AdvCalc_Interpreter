#include "token.h"

int isAssignment(Token tokens[], int tokensSize) {
    for (int i = 0; i < tokensSize; i++)
    {
        if (tokens[i].tokenType == EQUAL_SIGN)
        {
            return 1;
        }
        
    }
    
    return 0;
}

void assign(variableList *variable_list, Token tokens[], int tokensSize) {
    
}

int evaluate(Token tokens[], int begin, int end) {
    
}