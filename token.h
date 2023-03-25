typedef enum {
    OPERATOR_PLUS,
    OPERATOR_MINUS,
    OPERATOR_MULTIPLICATION,
    OPERATOR_AND,
    OPERATOR_OR,
    FUNCTION_XOR,
    FUNCTION_LS,
    FUNCTION_RS,
    FUNCTION_LR,
    FUNCTION_RR,
    FUNCTION_NOT,
    PARANTHESIS_OPENING,
    PARANTHESIS_CLOSING,
    SEPERETOR_COMMA,
    INTEGER,
    VARIABLE,
    EQUAL_SIGN,
    EMPTY,
} TokenType;

typedef struct{
    TokenType tokenType;
    int value;
    char *name;
}Token;
