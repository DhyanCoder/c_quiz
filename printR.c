#include <stdio.h>
#include "printR.h"
#include <string.h>


int printr(char arr[], int q_number) {
    //printf("-> %d.", number);
    int i = 0, c;
    printf("\t\t");
    for (; i < strlen(arr); i++) {
        c = arr[i];
        if (c == '\n'){
            printf("\n\t\t");
            continue;
        }
        putchar(c);
    }
    return 0;
}
