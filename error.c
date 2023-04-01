#include "token.h"
#include "helpers.h"
#include <stdio.h>


int isError (Token tokens[], int sizeOfTokens) {

    TokenType operators[] = {OPERATOR_AND, OPERATOR_MINUS, OPERATOR_MULTIPLICATION, OPERATOR_OR, OPERATOR_PLUS};
    const int NUM_OPERATORS = 5;
    TokenType funcsParen[] = {FUNCTION_LR, FUNCTION_LS, FUNCTION_NOT, FUNCTION_RR, FUNCTION_RS, FUNCTION_XOR};
    const int NUM_FUNC_PAREN = 6;
    TokenType openParan[] = {PARANTHESIS_OPENING};


    if (sizeOfTokens==0)
    {
        return 0;
    }
    
    // if there are more than one equal sign in a line
    else if (tokenTypeCounter(OTHER, tokens, sizeOfTokens)>0) {
        printf("undefined symbol\n");
        return 1;
    }

    else if (tokenTypeCounter(SEPERATOR_COMMA, tokens, sizeOfTokens)!=(tokenTypeCounter(FUNCTION_LR, tokens, sizeOfTokens)+ tokenTypeCounter(FUNCTION_LS, tokens, sizeOfTokens) +
    tokenTypeCounter(FUNCTION_RR, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_RS, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_XOR, tokens, sizeOfTokens))) {
        return 1;
    }
    

    else if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens) > 1) {
        printf("more than one equal sign\n");
        return 1;
    }

    // if there is an error in the number of parentheses
    else if (parCheck(tokens, sizeOfTokens)) {
        printf("parenthesis error\n");
        return 1;
    }

    // this error: ()
    else if (isSeq(tokens, sizeOfTokens, PARANTHESIS_OPENING, PARANTHESIS_CLOSING)) {
        printf("paranthesis error ---> ()\n");
        return 1;
    }

    // if there is sequential operation symbol
    else if (isSeqArr(tokens, sizeOfTokens, operators, NUM_OPERATORS, operators, NUM_OPERATORS)) {
        printf("sequential operation symbol\n");
        return 1;
    }

    //
    else if (isNotSeqArr(tokens, sizeOfTokens, funcsParen, NUM_FUNC_PAREN, openParan, 1)) {
        printf("paranthesis is needed after functions\n");
        return 1;
    }


    // if there is smt else except an alpha in the first part of the assignment
    else if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens)==1) {
        if (sizeOfTokens==1) {
            if (tokens[1].tokenType == EQUAL_SIGN) {
                if ((tokens[0].tokenType != VARIABLE)||(sizeOfTokens==2)) {
                    printf("faulty assignment error\n");
                    return 1;
                }
            } else {
                return 1;
            }
        }
    }

    else if ((tokenTypeCounter(FUNCTION_LR, tokens, sizeOfTokens)+ tokenTypeCounter(FUNCTION_LS, tokens, sizeOfTokens) +
    tokenTypeCounter(FUNCTION_RR, tokens, sizeOfTokens) + tokenTypeCounter(FUNCTION_RS, tokens, sizeOfTokens) 
    + tokenTypeCounter(FUNCTION_XOR, tokens, sizeOfTokens))>0)
    {
        if (twoArgFunc(tokens, sizeOfTokens, 0))
        {   
            printf("twoargfunc\n");
            return 1;
            
        }
    }
    
    
    

    
    //NO ERROR
    return 0;
}