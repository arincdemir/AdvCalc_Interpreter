#include <stdio.h>
#include <math.h>
#include "token.h"
#include "tokenList.h"
#include "error.h"

// slice a string starting start, ending end, and put it into the destination
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
// there is at least one sequential
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
// 0: there are never not sequential    1: there is at least one time, they come after them
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

//checks that whether there are two tokentype sequential
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

//if there is two-args-function check its requirements
int twoArgFunc(Token tokens[], int size, int startIndex) {
    if (startIndex==size+1) {
        return 0;
    } else if (startIndex==size-1) {
        return 1;
    } else if (startIndex==size) {
        return 1;
    }     
    Token retTokens1[256];
    int index;
    Token retTokens2[256]; 
    int index2;
    int index0 = 0;
    int a = 0;
    int i;
    for (i = startIndex; i < size; i++) {
        if ((a==0) && (tokens[i].tokenType == FUNCTION_LR || tokens[i].tokenType == FUNCTION_LS || tokens[i].tokenType == FUNCTION_RR ||
            tokens[i].tokenType == FUNCTION_RS || tokens[i].tokenType == FUNCTION_XOR)) {
            index = 0;
            index0 = i;
            for (int k = i+2; k < size; k++) {
                int whichComma = 0;
                if (tokens[k].tokenType == SEPERATOR_COMMA) {
                    if(whichComma==0) {
                        a=1;
                        i=k;
                        if (index==0) {
                            return 1; 
                        }                    
                        break;
                    } else {
                        whichComma--;
                    }
                } else if (tokens[i].tokenType == FUNCTION_LR || tokens[i].tokenType == FUNCTION_LS || tokens[i].tokenType == FUNCTION_RR ||
                           tokens[i].tokenType == FUNCTION_RS || tokens[i].tokenType == FUNCTION_XOR) {
                    whichComma++;
                    retTokens1[index] = tokens[k];
                    index++;
                } else {
                    retTokens1[index] = tokens[k];
                    index++;
                }
                
            } 
        }
        else if (a==1)
        {
            int count = 0;
            index2 = 0;
            while(i < size) {  
                if(tokens[i].tokenType == PARANTHESIS_OPENING) {
                    count++;
                } else if(tokens[i].tokenType == PARANTHESIS_CLOSING) {
                    count--;
                }
                if (count==-1) {
                    if (index2==0) {
                        return 1;
                    }   
                    
                    break;
                }
                
                retTokens2[index2] = tokens[i];
                index2++;
                i++;
            }
        } else return 0;
    }   

    if ((size>index+index2+4) && (tokens[index+index2+4].tokenType != OPERATOR_PLUS || tokens[index+index2+4].tokenType != OPERATOR_MINUS ||
    tokens[index+index2+4].tokenType != OPERATOR_MULTIPLICATION || tokens[index+index2+4].tokenType != OPERATOR_AND ||
    tokens[index+index2+4].tokenType != OPERATOR_OR)) return 1;
    //printf("index: %d  index2: %d\n", index, index2);
    //int isEr1 = isError(retTokens1, index);
    //int isEr2 = isError(retTokens2, index2);
    //int twoArg3 = twoArgFunc(tokens, size, index0+index+index2+5);
    //printf("isEr1: %d  isEr2: %d   twoArg3: %d\n", isEr1, isEr2, twoArg3);
    return isError(retTokens1, index) || isError(retTokens2, index2) || twoArgFunc(tokens, size, index0+index+index2+5);
}
