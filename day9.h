#ifndef DAY9
#define DAY9

#define ABS(value) ((value) > 0 ? (value) : -(value))

typedef struct info_param {
	int length;
	char *str;
	char *copy;
	char **word_array;
} s_info_param ;

s_info_param *my_params_to_array(int argc, char **argv);

int my_show_param_array(struct info_param, const *par);

#endif