#include <stdio.h>
#include <stdlib.h>
#include "day6.h"
#include "day3.h"

// copy a string into another, the destination string will already have enough memory in order to copy the source string
char* my_strcpy(char *dest, char const *src) {

	int i;

	for (i = 0; src[i] != '\0'; i++) {
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return dest;
}

// copy a string into another, the destination string will already have enough memory in order to copy n character given as a parameter
char* my_strncpy(char *dest, char const *src, int n) {

	int totalSrc = my_strlen(src);

	if (n <= totalSrc) {

		for (int i = 0; i < n; i++) {
			dest[i] = src[i];
		}

		dest[n] = '\0';

	}

	return dest;
}

// reverse a string
char* my_revstr(char *str) {

	int i = my_strlen(str) - 1;
	int j = 0;

	char tmp;

	while (i > 0) {

		tmp = str[j];

		str[j] = str[i];
		str[i] = tmp;

		i--;
		j++;

	}

	return str;

}

// finds the to_find string into the str, return the string to find if it found it, and the source string if not.
char* my_strstr(char *str, char const *to_find) {

	int i = 0;
	int j = 0;

	while (j != '\0') {

		if (to_find[i] == str[j]) {
			i++;
		} else {
			i = 0;
		}

		if (to_find[i] == '\0') {
			return to_find;
		}

		j++;
	}

	return str;

}

// compare two string, return -1 if str1 < str2, 1 if str1 > str2, 0 if they are equal
int my_strcmp(char const *s1, char const *s2) {

	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0') {

		if (s1[i] != s2[i]) {
			
			if (s1[i] < s2[i]) {
				return -1;
			}

			return 1;

		}

		i++;
	}

	return 0;
}

// compare the first n character of two string, return -1 if str1 < str2, 1 if str1 > str2, 0 if they are equal
int my_strncmp(char const *s1, char const *s2, int n) {

	int i = 0;

	while (i != n && (s1[i] != '\0' || s2[i] != '\0')) {

		if (s1[i] != s2[i]) {

			if (s1[i] < s2[i]) {
				return -1;
			}
			
			return 1;

		}

		i++;
	}

	return 0;

}

// put every letter in uppercase
char *my_strupcase(char *str) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;
		}

		i++;
	}

	return str;
}

// put every letter in lowercase
char *my_strlowcase(char *str) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}

		i++;
	}

	return str;
}

// put every letter of every word in uppercase and the others in lowercase
char *my_strcapitalize(char *str) {

	if (str[0] >= 'a' && str[0] <= 'z') {
		str[0] -= 32;
	}

	int i = 1;

	while (str[i] != '\0') {

		// lowercase to uppercase
		if (str[i] == ' ' && str[i+1] >= 'a' && str[i+1] <= 'z') {

			str[i + 1] -= 32;
		}

		// upercase to lowercase
		if (str[i - 1] != ' ' && str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}

		i++;
	}

	return str;
}

// return 1 if str contains only alphabetical character, 0 otherwise
int my_str_isalpha(char const *str) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z') {
			return 0;
		}

		i++;
	}

	return 1;

}

// return 1 if str only contains digits, 0 otherwise
int my_str_isnum(char const *str) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] < 48 || str[i] > 57) {
			return 0;
		}

		i++;
	}

	return 1;

}

// return 1 if str only containlower case alphabetical characters
int my_str_islower(char const *str) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] < 'a' || str[i] > 'z') {
			return 0;
		}

		i++;
	}

	return 1;

}

// convert and display a deciaml number into a number in a given base
int my_putnbr_base(int number, char const *base) {

	int baseSize = my_strlen(base);
	int result;

	if (number < 0) {
		my_putchar('-');
		my_putnbr_base(-number, base);
	}

	if(number > 0){

		result = number % baseSize;

		number = my_putnbr_base(number/ baseSize, base);

		my_putchar(base[result]);

	}

}

// find the position of a char in a given string and return its position, if the char is not found, return 0
int my_strchr(char const *str, char to_find) {

	int i = 0;

	while (str[i] != '\0') {

		if (str[i] == to_find) {
			return i;
		}

		i++;
	}

	return 0;

}

// convert a number in a given base into a decimal number
int my_getnbr_base(char const *str, char const *base) {

	int totalBase = my_strlen(base);
	int totalDigit = my_strlen(str);
	int i = 0;
	int res = 0;
	int digit;

	while (str[i] != '\0') {

		digit = my_strchr(base, str[i]);

		totalDigit -= 1;

		res += digit * (my_compute_power_rec(totalBase, totalDigit));

		i++;
	}

	return res;

}

// display a string, for any unprintable character, display it in hexadecimal base with a backslash before
int my_showstr(char const *str) {

	int i = 0;
	char hexa[] = "0123456789ABCDEF";

	while (str[i] != '\0') {

		if (str[i] < 31) {
			my_putchar('\\');
			my_putnbr_base(str[i], hexa);
		} else {
			my_putchar(str[i]);
		}

		i++;
	}

	return 0;
}