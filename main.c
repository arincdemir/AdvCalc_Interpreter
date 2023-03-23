#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "error.h"
#include "variableList.h"

int main()
{
    variableList *variable_list = createVariableList();
    addVariable(variable_list, "a", 31);
    addVariable(variable_list, "b", 69);
    printf("%d\n", getVariable(variable_list, "a"));
    printf("%d\n", getVariable(variable_list, "b"));
    while (1)
    {
        char input[256];
        fgets(input, 256, stdin);
        if (input == NULL)
        {
            break;
        }
        Token tokens[256];
        int size = getTokens(input, tokens);
        for (int i = 0; i < size; ++i)
        {
            printf("%d, %d, %s\n", tokens[i].tokenType, tokens[i].value, tokens[i].name);
        }

        if (isError(tokens, size))
        {
            printf("Error!\n");
            // Free the dynamic memory created in the lexer.
            for (int i = 0; i < size; ++i)
            {
                if (tokens[i].tokenType == VARIABLE)
                {
                    free(tokens[i].name);
                }
            }
            continue;
        }

        // Free the dynamic memory created in the lexer.
        for (int i = 0; i < size; ++i)
        {
            if (tokens[i].tokenType == VARIABLE)
            {
                free(tokens[i].name);
            }
        }
    }
    deleteList(variable_list);
}