#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "filehandler.h"
#include "selector.h"

int main()
{
    int c, on = 0, q_num[20], len_q = 0;
    int num_of_q = 60, ask_this = 0, answer = 0; // FIXME: MODIFY THIS AFTER ADDING QUESTIONS
    int score = 0;
    printf("\t\t#WISDOM,Check your c knowldege\n");
    do {
    printf("Press (s) to start game or (q) to quit: ");
    c = getchar();
    switch(c) {
        case 's':
            on = 1;
            break;
        case 'q':
            exit(0);
        default:
            printf("Command ni de pa rha hai bhai? khel payega? \n");
    }
    } while (!on);
    while (c != 'q')
    {
        ask_this = select(len_q, num_of_q, q_num);
        q_num[len_q++] = ask_this;

        answer = handle(ask_this);

        printf("Enter your answer : ");
        c = getchar();
        getchar();
        
        if (c == answer || tolower(c) == answer) {
            printf("Well done!\n");
            score += 10; // no need to changeFIXME:
        } else {
            printf("\n\n\nTumse na ho payega beta\nYour total score is %d", score);
            exit(0);
        }
        printf("\n\n");
    }
    return 0;
}

