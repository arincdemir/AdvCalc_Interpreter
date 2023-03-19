#include "token.h"
int getTokens(char *string, Token tokens[]) {
    int i = 0;
    while (i < 3){
        Token newToken;
        newToken.tokenType = INTEGER;
        newToken.value = i;
        newToken.name = "aaa";
        tokens[i] = newToken;
        i++;
    }
    return i;
}
