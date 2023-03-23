// Function that slices a string and copies it to destination starting at start(inclusive), ending at end(exclusive).
void sliceString(char *string, char *destination, int start, int end);

// counts how many parentheses are (output: 1 is error / 0 is no error)
int parCheck(Token tokens[], int size);

// counts how many same type tokens are
int tokenTypeCounter(TokenType type, Token tokens[], int size)