#pragma once
#include <string.h>
#include <stdio.h>
typedef char* string;

//splice function to splice the string

void splicer(string input, int start, int end) {
    char splicedString[200];
    strcpy(splicedString, input);

    while(start <= end) {
        printf("%c", splicedString[start]);
        start++;
    }

}