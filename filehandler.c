
#include "filehandler.h"
#include "printR.h"
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
char temp_storage[1500];
int top_ts = 0;

int handle(int number)
{
    top_ts = 0;
        FILE *fp;
    fp = fopen("questionsASCII.txt", "r");
    int c, count = 0;
    int storage = 0, on = 0, num = 0;
    
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
                // printf("Found number\n\n\n");
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
        if (!count) temp_storage[top_ts++] = (char) c; // FIXME:
        count = 0;
    }

    // printf("\t\t%s", temp_storage);
    printr(temp_storage, number);
    fclose(fp);
    return tolower(storage);

}