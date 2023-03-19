#include <stdio.h>
#include "token.h"
#include "lexer.h"

int main() {
    while (1){
        char input[256];
        fgets(input, 256, stdin);
        Token tokens[256];
        int size = getTokens(input, tokens);
        for (int i = 0; i < size; ++i) {
            printf("%d, %d, %s\n", tokens[i].tokenType, tokens[i].value, tokens[i].name);
        }

    }
}