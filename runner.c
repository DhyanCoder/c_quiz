#include <stdio.h>
#include "filehandler.h"
#include "selector.h"

int main()
{   
    /*
        print every rule and welcome things here.
    */
    int c, on = 0, q_num[20], len_q = 0;
    int num_of_q = 0, ask_this = 0, answer = 0; // FIXME: MODIFY THIS AFTER ADDING QUESTIONS
    int score = 0;
    printf("\t\tWELCOME\n");
    do {
    printf("press (s) to start game or (q) to quit: ");
    c = getchar();
    switch(c) {
        case 's':
            break;
        case 'q':
            exit(0);
        default:
            printf("Invalid command");
    }
    } while (!on);
    while ((c = getchar()) != 'q')
    {
        ask_this = select(len_q, num_of_q, q_num);
        answer = handle(ask_this);
        c = getchar();
        if (c == 'q') {
            printf("Your total score is %d", score);
            break;
        }
        if (answer == c) {
            printf("Well dome!\n");
            score += 10 // FIXME:
        } else {
            printf("Wrong answer\nYour total score is %d", score);
        }
        printf("\n\n");
    }
    return 0;
}

