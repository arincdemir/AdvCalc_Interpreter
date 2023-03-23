#include "token.h"
#include "helpers.h"

int isError (Token tokens[], int sizeOfTokens)
{
    // if there are more than one equal sign in a line
    if (tokenTypeCounter(EQUAL_SIGN, tokens, sizeOfTokens) > 1) {
        return 1;
    }

    // if there is an error in parentheses
    if (parCheck(tokens, sizeOfTokens)) {
        return 1;
    }

    //
    return 0;
}