#include <stdio.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char str[256];
    char str1[256];
    itoa(20, str, 2); //10100
    #ifndef HELPER_H
    //int bin = intToBinary(a);
    //printf("%d", log10(10));
    //printf("%d", loggg(bin));
    //int rem = bin % pow(10, nDigits-i);
    //bin = rem * pow(10, i) + bin/pow(10, nDigits-i);
    sliceString(str, str1, 0, 2);
    printf("%s", str1);
    #endif 

    return 0;
}

int rr(int a, int i) {
    return 0;
}

int not(int a) {
    return ~a;
}