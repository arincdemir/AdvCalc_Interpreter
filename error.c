#include "token.h"
#include "helpers.h"
#include <stdio.h>


int isError (Token tokens[], int sizeOfTokens) {

    TokenType operators[] = {OPERATOR_AND, OPERATOR_MINUS, OPERATOR_MULTIPLICATION, OPERATOR_OR, OPERATOR_PLUS};
    TokenType funcsParen[] = {FUNCTION_LR, FUNCTION_LS, FUNCTION_NOT, FUNCTION_RR, FUNCTION_RS, FUNCTION_XOR};
    TokenType openParan[] = {PARANTHESIS_OPENING};

    // if there are more than one equal sign in a line
    if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens) == -1) {
        printf("more than one equal sign ");
        return 1;
    }

    // if there is an error in the number of parentheses
    else if (parCheck(tokens, sizeOfTokens)) {
        printf("paren ");
        return 1;
    }

    // this error: ()
    else if (isSequential(tokens, sizeOfTokens, PARANTHESIS_OPENING, PARANTHESIS_CLOSING)) {
        printf("()");
        return 1;
    }

    // if there is sequential operation symbol
    else if (isSequential(tokens, sizeOfTokens, operators, operators)) {
        printf("sequential operation symbol");
        return 1;
    }

    // if there is sequential some functions
    else if (isNotSequential(tokens, sizeOfTokens, funcsParen, funcsParen)) {
        printf("functions cannot be sequential");
        return 1;
    }


    else if (isNotSequential(tokens, sizeOfTokens, funcsParen, openParan)) {
        printf("paranthesis is needed after functions");
        return 1;
    }


    // if there is smt else except an alpha in the first part of the assignment

    
    //NO ERROR
    return 0;
}