#include <stdio.h>
#include <stdlib.h>
#include "source.h"

int main() {

//

}

int my_compute_factorial_it(int nb) {

	int i = nb;

	while (i >= 1) {
		nb *= i;
		i--;
	}

	return nb;
}

int my_compute_factorial_rec(int nb) {

	if (nb >= 1) {
		return nb * my_compute_factorial_rec(nb - 1);
	}

	return 1;
}

int my_compute_power_it(int nb, int p) {

	int tmp = nb;

	while (p > 1) {

		nb = nb* tmp;
		p--;

	}

	return nb;

}

int my_compute_power_rec(int nb, int p) {

	if (p > 0) {
		return nb * my_compute_power_rec(nb, --p);
	}

	return 1;

}

int my_compute_square_root(int nb) {

	for (int i = 0; i < (nb/2) +1; i++) {

		if (nb == i*i) {
			return i;
		}

	}

	return 0;

}

int my_is_prime(int nb) {

	if (nb <= 1) {
		return 0;
	}

	if (nb <= 3) {
		return 1;
	}

	for (int i = 2; i <= nb/2; i++) {
		if (nb % i == 0) {
			return 0;
		}
	}

	return 1;

}

int my_find_prime_sup(int nb) {

	for (int i = nb; i <= nb*2; i++) {
		
		if (my_is_prime(i)) {
			return i;
		}
	}

	return 1;

}