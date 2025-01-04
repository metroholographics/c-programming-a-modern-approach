/* 
--------
04/01/2025
Enter 5 poker hands in [ranksuit] format e.g. 9c or th or qd
Bad cards or duplicate cards ignored
Programme analyses the hand in poker terms
--------
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HAND_SIZE 5
#define NUM_SUITS 4
#define NUM_RANKS 13

char suits[] = {'c', 'd', 'h', 's'};
char ranks[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};

int suit_count[NUM_SUITS] = {0};
int rank_count[NUM_RANKS] = {0};

char p_suits[HAND_SIZE];
char p_ranks[HAND_SIZE];

bool quit = false;
bool pair = false, three_pair = false, four_pair = false;
bool straight = false, flush = false, full_house = false;
bool straight_flush = false;

void reset_globals(void);
void read_hand(void);
void analyse_hand(void);
int  card_to_index(char c);
bool check_straight(void);
bool check_flush(void);
void print_hand(void);

int
main(void)
{
	while (true) {
		reset_globals();
		read_hand();
		if (quit) {
			break;
		}
		analyse_hand();
		print_hand();
	}
	return 0;
}

void
reset_globals(void)
{
	for (int i = 0; i < HAND_SIZE; i++) {
		p_suits[i] = '0';
		p_ranks[i] = '0';
	}

	for (int s = 0; s < NUM_SUITS; s++) {
		suit_count[s] = 0;
	}
	for (int r = 0; r < NUM_RANKS; r++) {
		rank_count[r] = 0;
	}
	pair = false, three_pair = false, four_pair = false;
	straight = false, flush = false, full_house = false;
	straight_flush = false;
}


void
read_hand(void)
{
	int added = 0;

	while (added < HAND_SIZE) {
		char r, s, c;
		bool valid_card = true, valid_rank = false, valid_suit = false, new_card = true;

		printf("Enter a card: ");
		r = getchar();
		s = getchar();

		while ((c = getchar()) != '\n') {
			if (c != ' ') {
				valid_card = false;
			}
		}

		if (r == '0') {
			quit = true;
			return;
		}

		for (int i = 0; i < NUM_RANKS; i++) {
			if (r == ranks[i]) {
				valid_rank = true;
				break;
			}
		}
		for (int i = 0; i < NUM_SUITS; i++) {
			if (s == suits[i]) {
				valid_suit = true;
				break;
			}
		}
		if (!valid_rank || !valid_suit || !valid_card) {
			printf("Bad card; ignored.\n");
			continue;
		}

		for (int i = 0; i < added; i++) {
			if (r == p_ranks[i] && s == p_suits[i]) {
				new_card = false;
				break;
			}
		}
		if (!new_card) {
			printf("Duplicate card; ignored.\n");
			continue;
		}

		p_ranks[added] = r;
		p_suits[added] = s;
		rank_count[card_to_index(r)]++;
		suit_count[card_to_index(s)]++;
		added++;
	}
}

int
card_to_index(char c)
{
	switch(c) {
		case 'c':
		case '2':
			return 0;
		case 'd':
		case '3':
			return 1;
		case 'h':
		case '4':
			return 2;
		case 's':
		case '5':
			return 3;
		case '6':
			return 4;
		case '7':
			return 5;
		case '8':
			return 6;
		case '9':
			return 7;
		case 't':
			return 8;
		case 'j':
			return 9;
		case 'q':
			return 10;
		case 'k':
			return 11;
		case 'a':
			return 12;
		default:
			return -1;
	}
}

void
analyse_hand(void)
{
	for (int i = 0; i < NUM_RANKS; i++) {
		if (rank_count[i] == 4) {
			four_pair = true;
		} else if (rank_count[i] == 3) {
			three_pair = true;
		} else if (rank_count[i] == 2) {
			pair = true;
		}
	}

	straight = check_straight();
	flush = check_flush();
	full_house = three_pair && pair;
	straight_flush = straight && flush;
	return;
}

bool check_straight(void)
{
	int lowest = 12;
	int highest = 0;

	for (int i = 0; i < HAND_SIZE; i++) {
		int current_rank = card_to_index(p_ranks[i]);

		if (current_rank < lowest) {
			lowest = current_rank;
		}
		if (current_rank > highest) {
			highest = current_rank;
		}
	}

	if (highest - lowest == 4) {
		return true;
	}

	return false;
}

bool check_flush(void)
{
	for (int i = 0; i < NUM_SUITS; i++) {
		if (suit_count[i] == 5) {
			return true;
		}
	}
	return false;
}

void
print_hand(void)
{
	if (straight_flush) {
		printf("Straight flush\n");
	} else if (four_pair) {
		printf("Four-of-a-kind\n");
	} else if (full_house) {
		printf("Full house\n");
	} else if (flush) {
		printf("Flush\n");
	} else if (four_pair) {
		printf("Four-of-a-kind\n");
	} else if (straight) {
		printf("Straight\n");
	} else if (three_pair) {
		printf("Three-of-a-kind\n");
	} else if (pair) {
		printf("Pair\n");
	} else {
		printf("High card\n");
	}
	return;
}

