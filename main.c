#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "error.h"
#include "variableList.h"
#include "evaluator.h"

int main()
{
    variableList *variable_list = createVariableList();
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

        changeVariables(tokens, size, variable_list);

        if (isAssignment(tokens, size))
        {
            assign(variable_list, tokens, size);
        }
        else {
            printf("evaluated: %d\n", evaluate(tokens, 0, size - 1));
        }

        printf("assigned: %d\n", getVariable(variable_list, "test"));
        
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