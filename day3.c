#include <stdio.h>;
#include "day3.h"

// display a single char
void my_putchar(char c)
{
	write(1, &c, 1);
}

// display the lowercase alphabet in ascending order
int my_print_alpha(void) {
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
		printf("%c ", letter);

	return 0;
}

// display the lowercase alphabet in descending order
int my_print_revalpha(void) {
	char letter;

	for (letter = 'z'; letter >= 'a'; letter--)
		printf("%c ", letter);

	return 0;
}

// display all digits
int my_print_digits(void) {
	
	int digit;

	for (digit = 0; digit <= 9; digit++)
		printf("%i", digit);

	return 0;
}

// display p if n is positive and n if it's negative
int my_isneg(int n) {
	
	if (n < 0) {
		printf("P");
	}
	else {
		printf("N");
	}

	return 0;
}

// display in ascending order, all numbers composed by 3 different digits
int my_print_comb(void) {

	for (int i = 0; i <= 9; i++) {

		for (int j = 0; j <= 9; j++) {
			
			for (int k = 0; k <= 9; k++) {
				
				if (i < j && j < k) {
					printf("%d%d%d, ", i, j, k);
				}

			}
		}

	}

	return 0;
}


