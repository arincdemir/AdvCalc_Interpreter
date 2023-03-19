#include "token.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int getTokens(char *string, Token tokens[]) {
    int size = 0;
    int inputLength = strlen(string) - 1;
    int i = 0;
    while (i < inputLength) {
        Token newToken;
        //printf("here");
        if (isdigit(string[i])) { // if char is a digit
            int j = i + 1;
            while (j < inputLength && isdigit(string[j])) { // calculate where the number ends
                j++;
            }
            int value = atoi(string + i);
            newToken.tokenType = INTEGER;
            newToken.value = value;
            i = j;
        } else if (string[i] == 43) { // if char is "+"
            newToken.tokenType = OPERATOR_PLUS;
            i++;
        }
        tokens[size] = newToken;
        size++;
    }
    return size;
}
