#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char message[100], c, end_c, letter;

    int index = -1, tracker;

    printf("Enter a sentence: ");
    
    while ((c = getchar()) != '\n') {
        if (c == '!' || c == '.' || c == '?') {
            end_c = c;
            break;
        } else {
            index++;
            message[index] = c;
        }
    }

    printf("Reversal of sentence: ");

    tracker = index;

    while (tracker >= 0) {
        letter = '0';
        while (letter != ' ') {
            letter = message[tracker];
            if (letter == ' ') {
                break;
            } else {
                tracker--;
            }
        }
        
        if (tracker < 0){
            tracker = 0;
        }

        for (int i = tracker; i <= index; i++) {
            if (i == tracker && tracker != 0) {
                continue;
            } else {
                putchar(message[i]);
            }
        }

        if (message[tracker] == ' ') {
            putchar(message[tracker]);
        }

        index = tracker - 1;
        tracker = index;
    }

    printf("%c\n", end_c);

    return 0;
}