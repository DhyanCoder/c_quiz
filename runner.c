#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "filehandler.h"
#include "selector.h"

int main()
{
    int c, on = 0, q_num[20], len_q = 0;
    int num_of_q = 60, ask_this = 0, answer = 0; // FIXME: MODIFY THIS AFTER ADDING QUESTIONS
    int score = 0, point = 10, right_answer_count = 0;
    printf("\n");

    //TODO: OPENING
    printf( "\t\t-------------\n"
            "\t\t|  WELCOME  |\n"
            "\t\t-------------\n"
            "\tPRESS (ENTER) KEY TO CONTINUE");
    getchar();
    printf(        
            "\n\tRules:"
            "\n\t|-> press (a) (b) (c) or (d) for\n"
                "\t\t correcponding correct option"
            "\n\t|->For each right Answer -> (%d) points"
            "\n\t|->The game will continue until \n\tyou give one wrong answer"
            "\n\t     You can press (q) anytime to QUIT the game\n"
            "\t-----------------------------------------------------\n"
            "\t-----------------------------------------------------\n"
            , point);
    do {
    printf("Press (s) to start game or (q) to quit: ");
    c = getchar();
    getchar();
    switch(c) {
        case 's':
            on = 1;
            break;
        case 'q':
            exit(0);
        default:
            printf( "\n\t----------------------------------"
                    "\n\t| COMMAND NI DE PA RHA HAI BHAI, |"
                    "\n\t|         KHEL PAAYEGA           |\n"
                    "\n\t----------------------------------");
    }
    } while (!on);
    while (c != 'q')
    {
        ask_this = select(len_q, num_of_q, q_num);
        q_num[len_q++] = ask_this;

        answer = handle(ask_this);
        printf("Enter your answer |-> ");
        c = getchar();
        getchar();
        // printf("answer = %c\n", c);
        
        if (c == answer || tolower(c) == answer) {
            printf( "\t\t---------------\n"
                    "\t\t---Well Done---\n"
                    "\t\t---------------\n");
            right_answer_count++;
            score += point; // no need to changeFIXME:
        } 
        else if(c == 'q') {
            printf("--QUITING---\n");
            break;
        }
        else {
            if (score == 0)
                printf("\n\n\nTUMSE NA HO PAYEGA BETA");
            
            printf("\nYour total score is %d", score);
            exit(0);
        }
        printf("\n\n");
        if (right_answer_count == num_of_q) {
            break;
        }
        if (right_answer_count >= 18) {
            printf("\n\n\n"
            "\n\tGGGGGG  RRRRR  EEEEEE      A     TTTTTTTTT" 
            "\n\tGG      RRRR   EEE        AAA       TTT"  
            "\n\tGG  GG  RRR    EEEEEE    AAAAA      TTT"
            "\n\tGG  GG  R R    EEE      A     A     TTT"
            "\n\tGGGGGG  R  R   EEEEEE  A       A    TTT"
            );
        }
    }
    printf( "--------------------------\n"
            "----------SCORE-----------\n"
            "--------------------------\n"
            "-------->%4d<---------\n"
    , score);
    return 0;
}