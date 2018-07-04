#include <stdio.h>
#include <stdlib.h>
#include "day7.h"
#include "day4.h"
#include "day3.h"
#include "day6.h"

// concatene two string
char *my_strcat(char *dest, char const *src) {

	int destSize = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0') {

		dest[destSize] = src[i];

		i++;
		destSize++;

	}

	dest[destSize] = '\0';
}

char *my_strncat(char *dest, char const *src, int nb) {

	int destSize = my_strlen(dest);
	int i = 0;

	while (src[i] != '\0' && i != nb) {

		dest[destSize] = src[i];

		i++;
		destSize++;

	}

	dest[destSize] = '\0';

}

int my_print_params(int argc, char **argv) {

	int i = 0;

	while (i != argc) {

		my_putstr(argv[i]);
		my_putchar('\n');

		i++;
	}

	return 0;

}

int my_rev_params(int argc, char **argv) {

	int i = argc -1;

	while (i >= 0) {

		my_putstr(argv[i]);
		my_putchar('\n');

		i--;
	}

	return 0;
}


int my_sort_params(int argc, char **argv) {

	for (int i = 0; i < argc; i++) {

		for (int j = 0; j < argc - 1; j++) {

			if (my_strcmp(argv[j], argv[j + 1]) == 1) {

				char *tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;

			}

		}

	}


}