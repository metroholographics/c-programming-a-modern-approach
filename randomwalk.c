#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

const char symbol = '^';
const char base = '.';

int main (void)
{
    char arr[10][10];

    int direction, curr_x, curr_y, next_x, next_y;
    bool valid_move = false;
    bool stuck_check;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = base;
        }
    }
    arr[0][0] = symbol;
    curr_x = 0;
    curr_y = 0;

    srand((unsigned) time(NULL));

    for (int i = 1; i < 26; i++) {
        next_x = 0;
        next_y = 0;
        bool illegal[4] = {false, false, false, false};

        while (!valid_move) {
            stuck_check = false;
            for (int i = 0; i < 4; i++) {
                if (illegal[i] == false) {
                    stuck_check = true;
                    break;
                }
            }

            if (stuck_check == false) {
                break;
            }

            do {
                direction = rand() % 4;
            } while (illegal[direction] == true);

            switch (direction) {
                case 0:
                    next_x = -1;
                    next_y = 0;
                    break;
                case 1:
                    next_x = 0;
                    next_y = 1;
                    break;
                case 2:
                    next_x = 1;
                    next_y = 0;
                    break;
                case 3:
                    next_x = 0;
                    next_y = -1;
                    break;
            }

            if (curr_y + next_y < 0 || curr_x + next_x < 0 || curr_y + next_y > 9 || 
                curr_x + next_x > 9 || arr[curr_y + next_y][curr_x + next_x] != base) {
                    valid_move = false;
                    illegal[direction] = true;
                } else {
                    valid_move = true;
                }
        }

        if (stuck_check == false) {
            break;
        }

        curr_y += next_y;
        curr_x += next_x;

        arr[curr_y][curr_x] = symbol;
        valid_move = false;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}