#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"


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
    int bin = intToBinary(a);
    i = i % 64;
    int rem = bin % (int) pow(10, 64-i);
    bin = rem * pow(10, i) + bin/pow(10, 64-i);
    return binToInt(bin);
}

int rr(int a, int i) {
    int bin = intToBinary(a);
    return lr(a, 64-i);
}

int not(int a) {
    return ~a;
}