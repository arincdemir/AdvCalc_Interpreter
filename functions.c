#include <stdio.h>
#include "helpers.h"
#include "token.h"

int xor(int a, int b){
    return a^b;
}

int ls(int a, int i) {
    return a << i;
}

int rs(int a, int i) {
    return a >> i;
}

int lr(int a, int i) {
    printf("%d", intToBinary(16));
    return 0;
}

int rr(int a, int i) {
    return 0;
}

int not(int a) {
    return ~a;
}