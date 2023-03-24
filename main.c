#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "lexer.h"
#include "error.h"

int main()
{
    while (1)
    {
        char input[256];
        fgets(input, 256, stdin);
        if (input == NULL)
        {
            //printf("111111111111111111111111111\n");
            break;
        }
        Token tokens[256];
        int size = getTokens(input, tokens);
        /*for (int i = 0; i < size; ++i)
        {
            printf("%d, %d, %s\n", tokens[i].tokenType, tokens[i].value, tokens[i].name);
        }*/
        

        if (isError(tokens, size))
        {
            printf("Error!\n");
        }

        // Free the dynamic memory created in the lexer.
        /*for (int i = 0; i < size; ++i)
        {
            printf("22222222222222222222222222222222\n");
            free(tokens[i].name);
            printf("3333333333333333333333333333333\n");
        }*/
        
        //printf("4444444444444444444444444444444444444\n");
        continue;
    }
}