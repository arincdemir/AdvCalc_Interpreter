#include "token.h"
#include "variableList.h"
#include <stdio.h>
#include "tokenList.h"
#include "functions.h"


void changeVariables(Token tokens[], int tokensSize, variableList *variable_list) {
    for (int i = 0; i < tokensSize; ++i) {
        if (tokens[i].tokenType == VARIABLE) {
            tokens[i].tokenType = INTEGER;
            tokens[i].value = getVariable(variable_list, tokens[i].name);
        }
    }
}

int isAssignment(Token tokens[], int tokensSize) {
    for (int i = 0; i < tokensSize; i++) {
        if (tokens[i].tokenType == EQUAL_SIGN) {
            return 1;
        }

    }

    return 0;
}

TokenList *infixToPostfix(TokenList *tokenList) {
    //implementation of the shunting yard algorithm
    TokenList *operatorStack = createTokenList();
    TokenList *output = createTokenList();
    while (tokenList->size > 0) {
        Token token = popBottom(tokenList);
        if (token.tokenType == INTEGER) { // if the token is an integer
            push(output, token);
        } else if (token.precedence == PRECEDENCE_FUNCTION) { // if token is a function
            push(operatorStack, token);
        } else if (token.precedence == PRECEDENCE_TIMES || token.precedence == PRECEDENCE_OR ||
                   token.precedence == PRECEDENCE_PLUS_MINUS ||
                   token.precedence == PRECEDENCE_AND) { // if the token is an operator
            while (operatorStack->size > 0 && (peekTop(operatorStack).precedence == PRECEDENCE_AND ||
                                               peekTop(operatorStack).precedence == PRECEDENCE_OR ||
                                               peekTop(operatorStack).precedence == PRECEDENCE_PLUS_MINUS ||
                                               peekTop(operatorStack).precedence ==
                                               PRECEDENCE_TIMES)) { // while there is an operator on top of the stack
                if (peekTop(operatorStack).precedence >= token.precedence) {
                    // if the precedence of the operator is bigger than the token, push it on the output
                    push(output, popTop(operatorStack));
                } else {
                    break;
                }
            }
            push(operatorStack, token);
        } else if (token.tokenType == SEPERATOR_COMMA) { // while the top operator is not a left paranthesis, push it
            while (operatorStack->size > 0 && peekTop(operatorStack).tokenType != PARANTHESIS_OPENING) {
                push(output, popTop(operatorStack));
            }
        } else if (token.tokenType == PARANTHESIS_OPENING) {
            push(operatorStack, token);
        } else if (token.tokenType == PARANTHESIS_CLOSING) {
            while (peekTop(operatorStack).tokenType != PARANTHESIS_OPENING) {
                push(output, popTop(operatorStack));
            }
            popTop(operatorStack); // get the left paranthesis and discard it
            if (operatorStack->size > 0 && peekTop(operatorStack).precedence == PRECEDENCE_FUNCTION) {
                push(output, popTop(operatorStack));
            }
        }
    }

    while (operatorStack->size > 0) {
        push(output, popTop(operatorStack));
    }

    return output;
}

int evaluatePostfix(TokenList *queue) {
    TokenList *stack = createTokenList();
    while (queue->size > 0) {
        Token token = popBottom(queue);
        if (token.tokenType == INTEGER) {
            push(stack, token);
        } else {
            Token ans;
            ans.tokenType = INTEGER;
            if (token.tokenType == OPERATOR_MULTIPLICATION) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = a.value * b.value;
            } else if (token.tokenType == OPERATOR_MINUS) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = b.value - a.value;
            }
            else if (token.tokenType == OPERATOR_PLUS) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = b.value + a.value;
            }
            else if (token.tokenType == OPERATOR_AND) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = b.value & a.value;
            }
            else if (token.tokenType == OPERATOR_OR) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = b.value | a.value;
            }
            else if (token.tokenType == FUNCTION_XOR) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = xor(b.value, a.value);
            }
            else if (token.tokenType == FUNCTION_LR) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = lr(b.value, a.value);
            }
            else if (token.tokenType == FUNCTION_LS) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = ls(b.value, a.value);
            }
            else if (token.tokenType == FUNCTION_NOT) {
                Token a = popTop(stack);
                ans.value = not(a.value);
            }
            else if (token.tokenType == FUNCTION_RR) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = rr(b.value, a.value);
            }
            else if (token.tokenType == FUNCTION_RS) {
                Token a = popTop(stack);
                Token b = popTop(stack);
                ans.value = rs(b.value, a.value);
            }

            push(stack,ans);
        }
    }

    return popTop(stack).value;
}

int evaluate(Token tokens[], int begin, int end) {
    TokenList *tokenList = createTokenList();
    for (int i = begin; i < end + 1; ++i) {
        push(tokenList, tokens[i]);
    }
    TokenList *postFix = infixToPostfix(tokenList);
    int size = postFix->size;
    //for (int i = 0; i < size; ++i) {
    //    Token pop = popBottom(postFix);
    //    printf("token: %d , %d \n", pop.tokenType, pop.value);
    //}
    return evaluatePostfix(postFix);
}

void assign(variableList *variable_list, Token tokens[], int tokensSize) {
    char *varName = tokens[0].name;
    addVariable(variable_list, varName, evaluate(tokens, 2, tokensSize - 1));
}

