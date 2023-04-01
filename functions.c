#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

#define BITS 64

int xor(long long a, long long b){
    return a^b;
}

int ls(long long a, long long i) {
    return a << i;
}

int rs(long long a, long long i) {
    return a >> i;
}


int lr(long long a, long long i) {
    return (a << i)|(a >> (BITS - i));
}

int rr(long long a, long long i) {
    return (a >> i)|(a << (BITS - i));
}

int not(long long a) {
    return ~a;
}