#include <stdio.h>
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
            printf("Command ni de pa rha hai bhai? khel payega?");
    }
    } while (!on);
    while (c != 'q')
    {
        ask_this = select(len_q, num_of_q, q_num);
        answer = handle(ask_this);
        c = getchar();
        if (answer == c) {
            printf("Well done!\n");
            score += 10// no need to changeFIXME:
        } else {
            printf("Tumse na ho payega beta\nYour total score is %d", score);
        }
        printf("\n\n");
    }
    return 0;
}

