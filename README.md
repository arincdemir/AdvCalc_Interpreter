# AdvCalc Interpreter
Made by:

- Arınç Demir
- Dağlar Eren Tekşen

For our Cmpe230 (Systems Programming) course project 1.

## Purpose
To create a python-like interpreter in C language. The interpreter should abide by operator precedence and associavity. Also the interpreter should have a few keywords for functions `not`, ` lr(left rotate)`, ` rr(right rotate)`, ` ls(left shift)`, ` rs(right shift)`, ` or` .

## Usage
Compile the C files using `gcc *.c -o advCalc.exe`. Then run the program by typing `./advCalc.exe`. The program should run and you can type your expressions or assignments in it. You can:
- Set variables some value. ex: `myVar = 3 + 2`
- Print the value of expressions. ex: `3 + ls(3,2)`

When you want to exit the program you can `Ctrl + C` on windows and mac, and `Ctrl + D` on linux.

## Implementation
We wrote this project in multiple files with one file serving only one purpose to make it easier to understand and debug.

#### token.h
Created the structure for tokens, and enums for token types and precedences. Tokens have three attributes `tokenType`, `value`, `name`. Value and name are attributed to the token only if it is an integer or variable respectively.

#### variableList.c
Created an arraylist implementation to match variable `names` and `values`. It has `addVariable(name, value)` for storing new variables or modifying existing ones, and `getVariable(name)` for accessing the stored values of the variables.

#### main.c
The entry program of the project. Here, our `variableList` is initialized. Inside an infinite while loop, input is taken and fed through `lexer.c` to get the token representation. After that, errors in the expression are checked by feeding the tokens to `error.c`. Then, the variables in the tokens are changed into their respected integer values with `changeVariables(tokens)` in `evaluator.c`. Whether the expression is an assignment or not is checked with `isAssignment(tokens)` in also `evaluator.c`. Finally if it is an assignment it is fed through `assign(tokens)` or else, `evaluate(tokens)`, again, both in `evaluator.c`.

#### lexer.c
In this file, the main function is `getTokens(expr)`. The expression is looped through characterwise in a loop, and tokens are created with the characters' respected tokenTypes. The precedences of the tokens are set if the tokens are operators. Also values of the integers and the names of the variables are taken here, and assigned to their respectful tokens. There are two additional functions `isReservedKeyword(str)`, and `getKeywordType(str)` for determining if a string represents one of the functions such as `lr` and `not`.

#### error.c
This file is used to check if the given expression is erronous. If an error exists, the program doesn't terminate, but prints `Error!` There are plenty of error types. Inorder to visualize, there are else-if and the functions that checks whether there is that spesific error type or not.

#### tokenList.c
Here, we have the implementation of a hybrid of queue and stack data structure that holds tokens. The implementation basically relies on doubly linked linked lists, and has `push()`, `popTop()`, `popBottom()`, `peekTop()` functionality. 

#### evaluator.c
This file has a few functions in it. First is `changeVariables(tokens, variableList)` which changes variable tokens into their respected integer value. Another function is `isAssignment(tokens)` which checks if the expression is an assignment. There is the function `assign(variableList, tokens)` which feeds the expression through `evaluate()`, and assigns the value of it to the variable at the left side of the equation. Another function is `evaluate(tokens)` which evaluates the end calculation of the tokens by first creating a tokenList with them, then feeding it through `infixToPostfix()`, and then feeding the return value of it to `evaluatePostfix()`. 

The mightiest function of this file is `infixToPostfix(tokenList)` which, as the name suggests, converts the infix expression to postfix. This function uses an extended version of the "Shunting Yard" algorithm which can also handle unary or binary prefix functions. The algorithm relies on pushing the operands on the output, and pushing the operators on top of a stack while the current operators precedence is larger than the top one. Another big function of this file is `evaluatePostfix(queue)` which evaluates a postfix expression using a stack to push integers into. When an operator is encountered, the topmost two integers are taken as its operands, and again the answer is pushed on top of the stack. The final remaining element in the stack is the final answer.

#### functions.c
Here, we implemented the reserved keyword functions of our program: `xor`, `ls`, `rs`, `lr`, `rr`, `not`. Only `lr` and `rr` have not a spesific character. We wrote them by hand. Then, we find the symbols of the rest.

#### helpers.c
Some helper functions that we used in other files. (Error-type-check functions included.)

## Difficulties Encountered
Doing this project, we had to overcome many dificulties, mainly caused by our inexperience with the C language. Here are some dificulties we encountered and how we solved them:
- Memory management: This was our first time that we wrote in a programming language without an included garbage collector. Our first problem occured when we realized that we cannot return variables that we just declared in a function, as it is stored in the stack memory and it is deleted after the function ends. So we got introduced the world of `malloc` and `free`. Now we acted much more careful what we wanted to store in the heap, and remembered to free it.
- Unavailability of OOP: As an oop fan myself, i found it really hard to work with a programming language that did not have objects and the dot notation to call methods. However, after a while I got used to the "C way of doing things", which is passing data as arguments to functions. Now that I am used to that, I actually find it an OK way of doing things.
- Unavailability of basic data types in C: As previous python and java programmers, we were used to finding the data types that we are looking for to be included in the standart libraries. However, it is not the case in C, and we had to write our own data structures. We needed two extra data types for this project:
  - Stack and queue: We implemented a data structure that can be used both as a stack and a queue using a doubly linked list.
  - Table for storing variables: The intuition here is to use a hashmap for O(1) operation cost. However, we found it to be overkill and just opted for an arraylist.
- Using git: We knew that using git to collaboratively develop a project the way to go. However, we did not know the best practices to use it. First, we were commiting into the main branch. After dealing with a few merge problems, we learned to always work on different branches. It worked fine for us, and we were able to complete the project with minimum number of conflicts.
- Error types are really hard to discover. We encounter a new type everyday and add that into our code.

## Conclusion
The AdvCalc Interpreter project is a Python-like interpreter written in C language for the Systems Programming course project. The project is implemented in multiple files, with each file having a specific purpose to make it easier to debug and understand. We created a token structure with three attributes tokenType, value, and name, an array list implementation to match variable names and values, and a hybrid of queue and stack data structure to hold tokens. Additionally, the project includes an error checker to identify erroneous expressions and a series of functions to evaluate expressions.  While implementing the project, we encountered several challenges, such as memory management, the absence of object-oriented programming, and the unavailability of basic data types in C. However, they overcame these challenges by using dynamic memory allocation, passing data as arguments to functions, and careful implementation of data types. Overall, it was a great project that thought us compiler design, working with C and working with a group.
