#pragma once
#include <stdio.h>

typedef struct String {
    char **arr;
    int size;
} _customStringType;


_customStringType initializeString(_customStringType *myString, int *s) {
    myString -> size = *s;

    printf("%d", myString -> size);
};