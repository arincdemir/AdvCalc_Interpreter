#include "token.h"
Token *getTokens(char *string) {
    static Token myToken;
    myToken.tokenType = INTEGER;
    myToken.value = 99;
    return &myToken;
}
