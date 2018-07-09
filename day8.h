#ifndef DAY8
#define DAY8

char *my_strdup(char const *src);
char *concat_params(int argc, char **argv);
char* my_strn2cpy(char *dest, char const *src, int n, char endOfString);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str, char separator);
int count_char_occurances(char *str, char to_find);
int count_char_until_separator(char *str, char separator);

#endif