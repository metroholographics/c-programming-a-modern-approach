/* 16/10/2024*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool	play_game(void);
int		roll_dice(void);

int
main(void)
{
	srand(time(NULL));
	bool r;
	char c;
	int num_w = 0, num_l = 0;
	
	while (true) {
		r = play_game();
		if(r) {
			printf("You win!\n");
			num_w += 1;
		} else {
			printf("You lose!\n");
			num_l += 1;
		}

		printf("Play again?: ");
		scanf(" %c", &c);
		if(c == 'y' || c == 'Y') continue;
		else break;
	}

	printf("Wins:%3d  Losses:%3d\n", num_w, num_l);
	return 0;
}

bool
play_game(void)
{
	int sum, point;

	sum = roll_dice();
	printf("You rolled: %d\n", sum);
	if(sum == 7 || sum == 11) return true;
	else if(sum == 2 || sum == 3 || sum == 12) return false;
	else {
		point = sum;
		printf("Your point is: %d\n", sum);
	}
	while(true) {
		sum = roll_dice();
		printf("You rolled: %d\n", sum);
		if(sum == point) return true;
		else if(sum == 7) return false;
	}
}

int
roll_dice(void)
{
	int d1, d2;

	d1 = (rand() % 6) + 1;
	d2 = (rand() % 6) + 1;

	return d1 + d2;
}

