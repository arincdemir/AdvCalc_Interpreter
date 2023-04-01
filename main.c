#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "error.h"
#include "variableList.h"
#include "evaluator.h"
#include "tokenList.h"

int main()
{
    // initialize the variable list
    variableList *variable_list = createVariableList();
    while (1)
    {
        char input[256];
        printf("> ");
        // take the input
        fgets(input, 256, stdin);
        if (input == NULL)
        {
            break;
        }
        Token tokens[256];
        // convert characters into tokens
        int size = getTokens(input, tokens);
        if (size==0) continue;  

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
        
        // change variable tokens into their respectful integer values
        changeVariables(tokens, size, variable_list);

        // check if expression is an assignment and depending on that, assign or evaluate
        if (isAssignment(tokens, size))
        {
            assign(variable_list, tokens, size);
        }
        else {
            printf("%d\n", evaluate(tokens, 0, size - 1));
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