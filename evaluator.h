#include "token.h"
#include "variableList.h"

#ifndef ADVCALC_INTERPRETER_EVALUATOR_H
#define ADVCALC_INTERPRETER_EVALUATOR_H

int isAssignment(Token tokens[], int tokensSize);

void assign(variableList *variable_list, Token tokens[], int tokensSize);

int evaluate(Token tokens[], int begin, int end);

void changeVariables(Token tokens[], int tokensSize, variableList *variable_list);

#endif //ADVCALC_INTERPRETER_EVALUATOR_H
