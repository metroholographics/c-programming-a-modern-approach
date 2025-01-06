/* 
--------
06/01/2025
Enter number (up to 10 digits, other characters ignored)
Display number in seven-segment format in terminal
--------
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

/* 7-segment representations for digits 0-9:
 *
 *    _0_
 * 5 |   | 1
 *   |_6_|
 * 4 |   | 2
 *   |_3_|
 */

int segments[MAX_DIGITS][7] = {{1,1,1,1,1,1,0},
							   {0,1,1,},
							   {1,1,0,1,1,0,1},
							   {1,1,1,1,0,0,1},
							   {0,1,1,0,0,1,1},
							   {1,0,1,1,0,1,1},
							   {1,0,1,1,1,1,1},
							   {1,1,1,},
							   {1,1,1,1,1,1,1},
							   {1,1,1,1,0,1,1}
							  };
char digits[4][MAX_DIGITS * 4];

void clear_digits_array(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			digits[i][j] = ' ';
		}
	}
	return;
}

void process_digit(int digit, int pos)
{
	for (int i = 0; i < 7; i++) {
		if (segments[digit][i] == 1) {
			switch (i) {
				case 0:	digits[0][pos * 4 + 1] = '_';
						break;
				case 1: digits[1][pos * 4 + 2] = '|';
						break;
				case 2: digits[2][pos * 4 + 2] = '|';
						break;
				case 3: digits[2][pos * 4 + 1] = '_';
						break;
				case 4: digits[2][pos * 4 + 0] = '|';
						break;
				case 5: digits[1][pos * 4 + 0] = '|';
						break;
				case 6: digits[1][pos * 4 + 1] = '_';
						break;	
			}
		}
	}
}

void print_digits_array(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++) {
			printf("%c", digits[i][j]);
		}
		printf("\n");
	}
}

int main(void)
{
	char c;
	int pos = 0;

	clear_digits_array();
	printf("Enter a number: ");
	while ((c = getchar()) != '\n' && pos < MAX_DIGITS) {
		if (isdigit(c)) {
			process_digit(c - '0', pos);
			pos++;
		}
	}

	print_digits_array();

	return 0;
}
