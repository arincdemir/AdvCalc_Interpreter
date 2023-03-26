// Function that slices a string and copies it to destination starting at start(inclusive), ending at end(exclusive).
void sliceString(char *string, char *destination, int start, int end);

// counts how many parentheses are (output: 1 is error / 0 is no error)
int parCheck(Token tokens[], int size);

// counts how many same type tokens are
int tokenTypeCounter(TokenType type, Token tokens[], int size);

// there is at least one sequential
int isSeqArr(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2);
int isSeq(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2);

// there is at least one not sequential
int isNotSeqArr(Token tokens[], int size, TokenType tokenTypes1[], int size1, TokenType tokenTypes2[], int size2);
int isNotSeq(Token tokens[], int size, TokenType tokenType1, TokenType tokenType2);