#include <stdio.h>
#include <stdlib.h>
#include "day9.h"
#include "day8.h"
#include "day7.h"
#include "day6.h"
#include "day5.h"
#include "day4.h"
#include "day3.h"

s_info_param *my_params_to_array(int argc, char **argv) {

	s_info_param *param;

	int i = 0;

	param = malloc(sizeof(s_info_param) * argc);

	while (i < argc) {

		param[i].length = my_strlen(argv[i]);
		param[i].str = argv[i];
		param[i].copy = my_strdup(argv[i]);
		param[i].word_array = my_str_to_word_array(argv[i], ' ');
		
		i++;
	}

	return param;
}

int my_show_param_array(struct info_param par1, const *par) {
	//
}