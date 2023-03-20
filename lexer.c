#include "token.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int isReservedKeyword(char *string) {
    if (strcmp(string, "xor") == 0 || strcmp(string, "ls") == 0 || strcmp(string, "rs") == 0 ||
        strcmp(string, "lr") == 0 ||
        strcmp(string, "rr") == 0 || strcmp(string, "not") == 0) {
        return 1;
    } else {
        return 0;
    }
}

TokenType getKeywordType(char *string) {
    if (strcmp(string, "xor") == 0) {
        return FUNCTION_XOR;
    } else if (strcmp(string, "ls") == 0) {
        return FUNCTION_LS;
    } else if (strcmp(string, "rs") == 0) {
        return FUNCTION_RS;
    } else if (strcmp(string, "lr") == 0) {
        return FUNCTION_LR;
    } else if (strcmp(string, "rr") == 0) {
        return FUNCTION_RR;
    } else if (strcmp(string, "not") == 0) {
        return FUNCTION_NOT;
    }
}

int getTokens(char *string, Token tokens[]) {
    int size = 0;
    int inputLength = strlen(string) - 1;
    int i = 0;
    while (i < inputLength) {
        Token newToken;
        //printf("here");
        if (string[i] == 32) { // if char is a space
            i++;
            continue;
        } else if (isdigit(string[i])) { // if char is a digit
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
            // check if name is a reserved keyword
            if (isReservedKeyword(name)) {
                newToken.tokenType = getKeywordType(name);
            } else {
                newToken.tokenType = VARIABLE;
                newToken.name = name;
            }
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
