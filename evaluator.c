#include "token.h"
#include "variableList.h"
#include "stdio.h"

void changeVariables(Token tokens[], int tokensSize, variableList *variable_list) {
    for (int i = 0; i < tokensSize; ++i) {
        if(tokens[i].tokenType == VARIABLE) {
            tokens[i].tokenType = INTEGER;
            tokens[i].value = getVariable(variable_list, tokens[i].name);
        }
    }
}

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


int evaluate(Token tokens[], int begin, int end) {
    return 31;
}

void assign(variableList *variable_list, Token tokens[], int tokensSize) {
    char *varName = tokens[0].name;
    addVariable(variable_list, varName, evaluate(tokens, 2, tokensSize - 1));
}

