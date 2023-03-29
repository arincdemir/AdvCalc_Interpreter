#include <stdio.h>
#include <math.h>
#include "token.h"

void sliceString(char *string, char *destination, int start, int end) {
    for (int i = 0; i < end - start; ++i) {
        destination[i] = string[start + i];
    }
}

// counts how many same type tokens are
int tokenTypeCounter(TokenType type, Token tokens[], int size) {
    int count = 0;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType == type) {
            count++;
        }
    }
    return count;
}

// counts how many parentheses are (output: 1 is error / 0 is no error)
int parCheck(Token tokens[], int size) {
    int count = 0;
    for(int i=0 ; i<size ; ++i) {
        if(tokens[i].tokenType == PARANTHESIS_OPENING) {
            count++;
        } else if(tokens[i].tokenType == PARANTHESIS_CLOSING) {
            count--;
        }
        if (count<0) {
            return 1;
        }
    }
    //printf("%d", count);
    if (count!=0) {
        return 1;
    }
    return 0;
}

// there is at least one sequential
// 0: hep art ardalar   1: en az bir kez art arda değiller
int isNotSeqArr(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (tokens[i].tokenType == tokenTypes1[j]) {
                for (int k = 0; k < size2; ++k) {
                    if (tokens[i+1].tokenType != tokenTypes2[k]) {
                        return 1;
                    }
                }  
            }
        }
    }
    return 0;
}

int isSeq(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2) {
    for (int i = 0; i < size - 1; ++i) {
        if (tokens[i].tokenType == tokenType1) {
            if (tokens[i+1].tokenType == tokenType2) {
                return 1;
            }
        }  
    }
    return 0;
    
}

// there is at least one not sequential
// 0: hiç art arda gelmediler   1: en az bir kez art arda geldi
int isSeqArr(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size1; ++j) {
            if (tokens[i].tokenType == tokenTypes1[j]) {
                for (int k = 0; k < size2; ++k) {
                    if (tokens[i+1].tokenType == tokenTypes2[k]) {
                        return 1;
                    }
                }  
            }
        }
    }
    return 0;
}

int isNotSeq(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2) {
    for (int i = 0; i < size - 1; ++i) {
        if (tokens[i].tokenType == tokenType1) {
            if (tokens[i+1].tokenType != tokenType2) {
                return 1;
            }
        }  
    }
    return 0;
}

int intToBinary(int dec) {
    if (dec==0) return 0;
    if (dec==1) return 1;
    return (dec%2) + 10 * intToBinary(dec/2);
}

int loggg(int num) {
    if (num==0) return 0;
    else if (num<10) return 1;
    return 1 + loggg(num/10);
}

int binToInt(int bin) {
    int dec = 0;
    int nDigit = loggg(bin);
    for (int i = 0; i < nDigit; i++) {
        dec += (bin % 10) * pow(2, i);
        bin = bin / 10;
    }
    return dec;
}
