#ifndef ADVCALC_INTERPRETER_TOKEN_H
#define ADVCALC_INTERPRETER_TOKEN_H


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
    SEPERATOR_COMMA,
    INTEGER,
    VARIABLE,
    EQUAL_SIGN,
    EMPTY,
    OTHER,
} TokenType;

typedef enum {
    PRECEDENCE_OR,
    PRECEDENCE_AND,
    PRECEDENCE_PLUS_MINUS,
    PRECEDENCE_TIMES,
    PRECEDENCE_FUNCTION,
    PRECEDENCE_EMPTY,
}Precedence;

typedef struct{
    TokenType tokenType;
    long long value;
    char *name;
    Precedence precedence;
}Token;

#endif