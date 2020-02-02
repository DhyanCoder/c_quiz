#include "filehandler.h"
#include <stdio.h>
#include <ctype.h>
/*
    prints the question according to argument number
    and returns answer as int
    97 for a
    98 for b
    99 for c
    100 for d
*/
int anc = 10000; // FIXME:

int handle(int number)
{
        FILE *fp;
    fp = fopen("questions.txt", "r");
    int c, count = 0;
    int storage = 0, on = 0, num = 0;
    printf("Asked question is -> %d", number); // FIXME:
    while ((c = fgetc(fp)) != EOF) {
        if (count == 3) {
            switch(c) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    num = (num * 10) + (c - '0');
                    continue;
            }
            if (num == number) {
                printf("Found number\n\n\n");
                break;
            }
            else {
                count = 0;
                num = 0;
                continue;
            }
        }
        if (c == '_') {
            count++;
            continue;
        }
    }

    if (c == EOF) {
        printf("cannot fine question");
        fclose(fp);
        return 0;
    }
    count = 0;
    while ((c = fgetc(fp)) != EOF)
    {
        if (on) break;
        if (count == 3) {
            switch (c)
            {
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                    storage = c;
                    on = 1;
                    break;
            }
            if (!on) {
                printf("___");
                count = 0;
            }
        }
        if (c == '_') {
            count++;
            continue;
        }
        if (!count) putchar(c);
        count = 0;
    }
    
    fclose(fp);
    return tolower(storage);

}