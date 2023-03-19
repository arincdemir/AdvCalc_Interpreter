#include "token.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

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
        } else if (isalpha(string[i])) { // if char is a english character
            int j = i + 1;
            while (j < inputLength && isalpha(string[j])) {
                j++;
            }
            // todo dont forget to free the memory allocated!
            char *name = calloc(j - i, sizeof(char));
            sliceString(string, name, i, j);
            // todo check if name is a reserved keyword
            newToken.tokenType = VARIABLE;
            newToken.name = name;
            i = j;
        } else if (string[i] == 43) { // if char is "+"
            newToken.tokenType = OPERATOR_PLUS;
            i++;
        } else if (string[i] == 45) { // if char is "-"
            newToken.tokenType = OPERATOR_MINUS;
            i++;
        } else if (string[i] == 42) { // if char is "*"
            newToken.tokenType = OPERATOR_MULTIPLICATION;
            i++;
        } else if (string[i] == 38) { // if char is "&"
            newToken.tokenType = OPERATOR_AND;
            i++;
        } else if (string[i] == 124) { // if char is "|"
            newToken.tokenType = OPERATOR_OR;
            i++;
        } else if (string[i] == 40) { // if char is "("
            newToken.tokenType = PARANTHESIS_OPENING;
            i++;
        } else if (string[i] == 41) { // if char is ")"
            newToken.tokenType = PARANTHESIS_CLOSING;
            i++;
        } else if (string[i] == 44) { // if char is ","
            newToken.tokenType = SEPERETOR_COMMA;
            i++;
        }
        tokens[size] = newToken;
        size++;
    }
    return size;
}
