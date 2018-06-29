#include <stdio.h>
#include <stdlib.h>

int main() {

	//
}

// display a single char
void my_putchar(char c) {
	write(1, &c, 1);
}

// swap 2 integers
void my_swap(int *a, int *b) {

	int saveA = *a;
	int saveB = *b;

	*a = saveB;
	*b = saveA;
}

// swap 2 chars
void my_swap_char(char *a, char *b) {

	char saveA = *a;
	char saveB = *b;

	*a = saveB;
	*b = saveA;
}

// Display a string
void my_putstr(char const *str) {

	int count = 0;

	while (str[count] != NULL) {
		my_putchar(str[count++]);
	}

}

// Return the string size
int my_strlen(char const *str) {
	 
	int count = 0;

	while (str[count] != NULL) {
		count++;
	}

	return count;

}

// Swap each character 2 by 2
char *my_evil_str(char *str) {
	int last = 0;
	last = my_strlen(str) -1;

	for (int i = 0; i < last-i; i++) {
		
		if (str[i] != str[last - i]) {
			my_swap_char(&str[i], &str[last - i]);

		}

	}

	return str;
}

// Display number given as parameter
int my_put_nbr(int nb) {
	
	int end = 1;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}

	int tmp = nb;
	int divisor = 1;

	while (tmp > 10) {
		tmp = tmp / 10;
		divisor *= 10;
	}

	while (nb > 9) {

		my_putchar((nb / divisor) + '0');
		nb = nb % divisor;
		divisor = divisor / 10;
	}

	my_putchar(nb + '0');

	return 0;

}

// Display number given as parameter/ recursive version
int my_put_nbr_rec(int nb) {
	
	if (nb < 0) {
		my_putchar('-');
		my_put_nbr_rec(-nb);
	} else if (nb > 9) {
		my_put_nbr_rec(nb / 10);
		my_putchar(nb % 10 + '0');
	}
	else {
		my_putchar(nb + '0');
	}
	
}

// Return a number as a string
int my_getnbr(char const *str) {
	int count = my_strlen(str);
	int res = 0;
	int multi = 1;

	while (count > 0) {

		res += (str[count -1] -'0') * multi;
		multi *= 10;

		count--;
	}

	return res;

}

// Sort an array
int my_sort_int_array(int *array, int size) {

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size - 1; j++) {

			if (array[j] > array[j + 1]) {

				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

			}

		}

	}

	return array;

}