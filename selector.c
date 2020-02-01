
#include "selector.h"
#include<time.h>
#define TRUE  1
#define FALSE 0

/*
  Returns an random int in range [1, last]
  which are not part of arr
*/

int select(int len, int last, int arr[])
{
    int generated_num = -1;
    int i = 0;
    int done = FALSE;
    srand(time(0));
    do {
        generated_num = (rand()%(last-1+1)) + 1;    
        for (; i < len; i++)
            if (generated_num == arr[i]) break;
        if (i == len) done = TRUE;
    } while(!done);
    return generated_num;
}