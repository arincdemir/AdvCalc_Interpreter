
#ifndef ADVCALC_INTERPRETER_VARIABLE_LIST_H
#define ADVCALC_INTERPRETER_VARIABLE_LIST_H

struct arrayNode
{
    char *string;
    int value;
};
typedef struct variableList
{
    int size;
    struct arrayNode *array;
} variableList;

void addVariable(variableList *list, char *name, int value);

variableList *createVariableList();

int getVariable(variableList *list, char *name);

void deleteList(variableList *list);

#endif