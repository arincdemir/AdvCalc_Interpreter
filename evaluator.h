int isAssignment(Token tokens[], int tokensSize);

void assign(variableList *variable_list, Token tokens[], int tokensSize);

int evaluate(Token tokens[], int begin, int end);

void changeVariables(Token tokens[], int tokensSize, variableList *variable_list);