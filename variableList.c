#include "variableList.h"
#include <stdlib.h>
#include <string.h>

void addVariable(variableList *list, char *name, int value)
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

variableList *createVariableList()
{
    variableList *list = malloc(sizeof(variableList));
    list->size = 0;
    list->array = malloc(128 * sizeof(struct arrayNode));
    return list;
}

int getVariable(variableList *list, char *name)
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

void deleteList(variableList *list)
{
    free(list->array);
    free(list);
}