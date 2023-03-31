# AdvCalc Interpreter
Made by:

- Arınç Demir
- Dağlar Eren Tekşen

For our Cmpe230 (Systems Programming) course project 1.

## Purpose
To create a python-like interpreter in C language. The interpreter should abide by operator precedence and associavity. Also the interpreter should have a few keywords for functions `not, lr(left rotate), rr(right rotate), ls(left shift), rs(right shift), or` .

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

### lexer.c
In this file, the main function is `getTokens(expr)`. The expression is looped through characterwise in a loop, and tokens are created with the characters' respected tokenTypes. The precedences of the tokens are set if the tokens are operators. Also values of the integers and the names of the variables are taken here, and assigned to their respectful tokens. There are two additional functions `isReservedKeyword(str)`, and `getKeywordType(str)` for determining if a string represents one of the functions such as `lr` and `not`.

## Difficulties Encountered
