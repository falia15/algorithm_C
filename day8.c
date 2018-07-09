#include <stdio.h>
#include <stdlib.h>
#include "day8.h"
#include "day7.h"
#include "day4.h"
#include "day3.h"

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

// display the content of an array of words, each word must end with \n
int my_show_word_array(char *const *tab) {

	int i = 0;

	while (tab[i] != '\0') {
		my_putstr(tab[i]);
		my_putchar('\n');
		i++;
	}

}

// count the number of time to_find is on the given param str
int count_char_occurances(char *str, char to_find) {

	int i = 0;
	int count = 0;

	while (str[i] != '\0') {

		if (str[i] == to_find) {
			count++;
		}
		i++;
	}

	return count;
}

// count the number of char of a string until the given separator
int count_char_until_separator(char *str, char separator) {

	int i = 0;

	while (str[i] != '\0' && str[i] != separator) {
		i++;
	}

	return i;
}

// Split a string every time | is 
char **my_str_to_word_array(char const *str, char separator) {

	int i = 0;
	int k = 0;
	int count = count_char_until_separator(&str[i], separator);
	char **res;

	res = malloc(count_char_occurances(str, separator) + 2);

	while (count != 0) {

		res[k] = malloc(count + 1);

		my_strncpy(res[k], &str[i], count);

		k++;
		i += count;

		if (str[i] != '\0') {
			i++;
		}

		count = count_char_until_separator(&str[i], separator);
	}

	res[k] = '\0';

	return res;
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to) {

}