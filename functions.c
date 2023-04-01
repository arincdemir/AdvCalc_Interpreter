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
    int nDigits = loggg(bin);
    i = i % nDigits;
    int rem = bin % (int) pow(10, nDigits-i);
    bin = rem * pow(10, i) + bin/pow(10, nDigits-i);
    return binToInt(bin);
}

int rr(int a, int i) {
    int bin = intToBinary(a);
    int nDigits = loggg(bin);
    return lr(a, nDigits-i);
}

int not(int a) {
    return ~a;
}