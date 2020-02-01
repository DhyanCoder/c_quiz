
#include "selector.h"
#include<time.h>
#define TRUE  1
#define FALSE 0

/*
  Returns an random int in range [1, last]
  which are not part of arr

int select(int len, int last, int arr[])
{
    int generated_num = -1;
    int i = 0;
    int done = FALSE;
    do {
        // TODO: RANDOM NUMBER GENERATOR
        void random (int lower, int last){
            for(;i<2;i++){
                int generated_num=(rand()%(last-lower+1))+lower;
                printf("%d",generated_num);

            }
        }
        for (; i < len; i++)
            if (generated_num == arr[i]) break;
        if (i == len) done = TRUE;
    } while(!done);
    return generated_num;
}
int main(){
            lower=1,last=10;
            srand(time(0));
            random(lower,last);
            int select(len,last,arr[])
            return 0;
        }
        */
                
void Randoms(int lower, int upper, int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int generated_num = (rand() % (upper - lower + 1)) + lower; 
        printf("%d ", generated_num); 
    } 
} 
int main() 
{ 
    int lower = 1, upper = 60, count = 1;  
    srand(time(0)); 
    Randoms(lower, upper, count); 
    return 0; 
} 
