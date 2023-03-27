#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sliceString(char *string, char *destination, int start, int end);

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
    int bin = 0;
    char str[256];
    char str1[256];
    char str2[256];

    itoa(a, str, 2);
    printf("1. %s\n", str);
    #ifndef HELPER_H
    sliceString(str, str1, 0, i);
    printf("%s\n", str);
    sliceString(str, str2, i, strlen(str));
    printf("%s\n", str2);

    #endif 
    printf("%s", str2);
    strcat(str1, str2);
    printf("%s", str1);
    
    return 0;
}

int rr(int a, int i) {
    return 0;
}

int not(int a) {
    return ~a;
}