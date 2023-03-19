#include <stdio.h>
#include "token.h"
#include "lexer.h"

int main() {
    while (1){
        char input[256];
        scanf("%s", input);
        Token *tokens = getTokens(input);

        printf("%d\n", tokens[0].value);
    }
}