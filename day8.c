#include <stdio.h>
#include <stdlib.h>
#include "day8.h"
#include "day7.h"

// allocates memory and copy the src string
char *my_strdup(char const *src) {

	int strSize = my_strlen(src);

	char *dest = malloc(strSize);

	return my_strcpy(dest, src);

}

// copy a string into another from n, the destination string will already have enough memory in order to copy n character given as a parameter
char* my_strn2cpy(char *dest, char const *src, int n, char endOfString) {

	int i = 0;

	while (src[i] != '\0') {

		dest[n] = src[i];

		n++;
		i++;

	}

	dest[n] = endOfString;

	return dest;
}

// concatene param on a single new string, sparated by /n
char *concat_params(int argc, char **argv) {

	int i = 0;
	int sizeStrings = 0;

	while (i < argc) {

		sizeStrings += my_strlen(argv[i]);

		i++;
	}

	char *dest = malloc(sizeStrings + argc);

	i = 0;
	int copyStart = 0;

	while (i < argc) {

		my_strn2cpy(dest, argv[i], copyStart, '\n');

		copyStart += my_strlen(argv[i]) + 1;

		i++;

	}

	dest[copyStart] = '\0';

	return dest;

}

