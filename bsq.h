#ifndef BSQ-H
#define BSQ-H

#include <stdlib.h>

typedef struct s_map
{
	int rows;
	char obs;
	char empty;
	char full;
	int cols;
	char **map_data;
} t_map;

int ft_is_printable(char c);
int get_clean_len(char *str);
int are_chars_valid(char empty, char obs, char full);
int str_to_positive_int(char *str, int len);
#endif