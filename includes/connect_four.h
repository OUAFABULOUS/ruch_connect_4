#ifndef CONNECT_FOUR
#define CONNECT_FOUR
#include "get_next_line.h"
#include "libft.h"
#include "stdint.h"
#include "stdio.h"


typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	int		len;
}			t_buf;

typedef uint64_t bitstr_t;


typedef struct s_state
{
	bitstr_t *board;
	bitstr_t *mask;
}			t_state;

typedef	struct s_game
{
	int64_t lines;
	int64_t cols;
	t_state curr_state;
	int64_t nb_cases;
	int32_t board_len;
}			t_game;

#endif