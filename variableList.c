#include "variableList.h"
#include <stdlib.h>
#include <string.h>

// either find an existing variable and modify it, or add a new variable
void addVariable(variableList *list, char *name, long long value)
{
    int size = list->size;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(name, list->array[i].string) == 0)
        {
            list->array[i].value = value;
            return;
        }
    }

    size = ++list->size;
    list->array[size - 1].string = name;
    list->array[size - 1].value = value;
}

// create a variablelist and assign memory to it and the array of it
variableList *createVariableList()
{
    variableList *list = malloc(sizeof(variableList));
    list->size = 0;
    list->array = malloc(128 * sizeof(struct arrayNode));
    return list;
}

// search through the array to find and return a variable. defaults to 0
long long getVariable(variableList *list, char *name)
{
    int size = list->size;
    for (size_t i = 0; i < size; i++)
    {
        if (strcmp(name, list->array[i].string) == 0)
        {
            return list->array[i].value;
        }
    }

    return 0;
}

// free the memory allocated with malloc
void deleteList(variableList *list)
{
    free(list->array);
    free(list);
}