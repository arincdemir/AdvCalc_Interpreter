#include "token.h"
#include "helpers.h"
#include <stdio.h>

int isError(Token tokens[], int sizeOfTokens)
{

    TokenType operators[] = {OPERATOR_AND, OPERATOR_MINUS, OPERATOR_MULTIPLICATION, OPERATOR_OR, OPERATOR_PLUS};
    const int NUM_OPERATORS = 5;
    TokenType funcsParen[] = {FUNCTION_LR, FUNCTION_LS, FUNCTION_NOT, FUNCTION_RR, FUNCTION_RS, FUNCTION_XOR};
    const int NUM_FUNC_PAREN = 6;
    TokenType openParan[] = {PARANTHESIS_OPENING};
    TokenType varAndInt[] = {VARIABLE, INTEGER};
    TokenType closeParan[] = {PARANTHESIS_CLOSING};
    TokenType cantComeAfterClosParan[] = {FUNCTION_LR,FUNCTION_LS,FUNCTION_NOT,FUNCTION_RR,FUNCTION_RS,FUNCTION_XOR,PARANTHESIS_OPENING,INTEGER,VARIABLE};
    //printf("in isError\n");

    //if there is no tokens move on
    if (sizeOfTokens==0)
    {   
        return 0;
    }

    else if (tokens[0].tokenType == OPERATOR_AND || tokens[0].tokenType == OPERATOR_OR || tokens[0].tokenType == OPERATOR_MINUS || tokens[0].tokenType == OPERATOR_PLUS || tokens[0].tokenType == OPERATOR_MULTIPLICATION
    || tokens[sizeOfTokens - 1].tokenType == OPERATOR_AND || tokens[sizeOfTokens - 1].tokenType == OPERATOR_OR || tokens[sizeOfTokens - 1].tokenType == OPERATOR_MINUS || tokens[sizeOfTokens - 1].tokenType == OPERATOR_PLUS || tokens[sizeOfTokens - 1].tokenType == OPERATOR_MULTIPLICATION)
    {
        return 1;
    }

    // if there are more than one equal sign in a line
    else if (tokenTypeCounter(OTHER, tokens, sizeOfTokens)>0) {
        //printf("undefined symbol\n");
        return 1;
    }

    //if the number of comma should be same with the functions that receive two argument
    else if (tokenTypeCounter(SEPERATOR_COMMA, tokens, sizeOfTokens)!=(tokenTypeCounter(FUNCTION_LR, tokens, sizeOfTokens)+ tokenTypeCounter(FUNCTION_LS, tokens, sizeOfTokens) +
    tokenTypeCounter(FUNCTION_RR, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_RS, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_XOR, tokens, sizeOfTokens))) {
        return 1;
    }
    
    //there cannot be more than ONE equal sign
    else if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens) > 1) {
        //printf("more than one equal sign\n");
        return 1;
    }

    // if there is an error in the number of parentheses
    else if (parCheck(tokens, sizeOfTokens))
    {
        //printf("parenthesis error\n");
        return 1;
    }

    //there are some tokenType's that cannot come after close paranthesis
    else if (isSeqArr(tokens, sizeOfTokens, closeParan, 1, cantComeAfterClosParan, 9))
    {
        //printf("close paran");
        return 1;
    }
    

    // this error: ()
    else if (isSeq(tokens, sizeOfTokens, PARANTHESIS_OPENING, PARANTHESIS_CLOSING)) {
        //printf("paranthesis error ---> ()\n");
        return 1;
    }

    // if there is sequential operation symbol
    else if (isSeqArr(tokens, sizeOfTokens, operators, NUM_OPERATORS, operators, NUM_OPERATORS)) {
        //printf("sequential operation symbol\n");
        return 1;
    }

    //variables and integers cannot come after themselves
    else if (isSeqArr(tokens, sizeOfTokens, varAndInt , 2, varAndInt, 2 )) {
        //printf("sequential integer or variable\n");
        return 1;
    }

    //paranthesis is needed after functions
    else if (isNotSeqArr(tokens, sizeOfTokens, funcsParen, NUM_FUNC_PAREN, openParan, 1)) {
        //printf("paranthesis is needed after functions\n");
        return 1;
    }

    // if there is smt else except an alpha in the first part of the assignment
    else if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens) == 1)
    {
        if (sizeOfTokens == 1)
        {
            if (tokens[1].tokenType == EQUAL_SIGN)
            {
                if ((tokens[0].tokenType != VARIABLE) || (sizeOfTokens == 2))
                {
                    //printf("faulty assignment error\n");
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
    }

    //if there is two-args-function check its requirements
    else if ((tokenTypeCounter(FUNCTION_LR, tokens, sizeOfTokens)+ tokenTypeCounter(FUNCTION_LS, tokens, sizeOfTokens) +
    tokenTypeCounter(FUNCTION_RR, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_RS, tokens, sizeOfTokens) 
    + tokenTypeCounter(FUNCTION_XOR, tokens, sizeOfTokens))>0)
    {
        if (twoArgFunc(tokens, sizeOfTokens, 0))
        {   
            //printf("twoargfunc\n");
            return 1;
        }
    }

    // printf("NO ERROR\n");
    // NO ERROR
    return 0;
}