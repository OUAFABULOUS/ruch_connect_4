#include "connect_four.h"

int print_err(const char *err_msg)
{
	write(2, err_msg, ft_strlen(err_msg));
	return (1);
}

void set_bit(t_game *game, bitstr_t *board, int n)
{
	board[n >> 6] |= (((bitstr_t)1 << n));
}

void print_board(t_game *game, bitstr_t *board)
{
	printf("%ld %ld %ld\n", game->lines, game->cols, game->nb_cases);
	printf("%lu\n", *board);
	for (int i = 0; i < game->lines; ++i)
	{
		for (int64_t n = game->lines - 1 - i; n <= game->nb_cases - 2 - i; n = n + game->lines + 1)
		{
			if (board[n >> 6] & ((bitstr_t)1 << n))
				printf("1 ");
			else
				printf("0 ");
		}
		printf("\n");
	}
}

int check_win(t_game *game, bitstr_t *board)
{
	// horizontal
	int	game_lines = game->lines + 1;
	int	nb_cases;

	nb_cases = game->board_len * 64;
	printf("board len %d\n", game->board_len);

	bitstr_t *shift_left = (bitstr_t *)malloc(game->board_len * sizeof(bitstr_t));
	ft_memcpy(shift_left, board, game->board_len * sizeof(bitstr_t));

	for (int i = 0; i < game->board_len; ++i)
	{
		// if (nb_cases >= (game_nb_cases))
		// 	shift_left[i] &= shift_left[i] >> (game->lines + 1);
		// else
		// {
		// 	i++;
		// 	shift_left[i] &= shift_left[i] >> ((game->lines + 1)) - 64;

		// }
		// if (shift_left[i] & (shift_left[i] >> ((game->lines + 1) * 2)))
		// 	return (1);
		

		shift_left[i] &= shift_left[i] >> game_lines;
		
		if (shift_left[i] & (shift_left[i] >> (game_lines * 2)))
			return (1);
		if (i >= 1)
		{
			shift_left[i - 1] >> 61;
			
		}
		
	}
	free(shift_left);
	return (0);
}

void drop_token(int32_t lines, t_state s, int col)
{
	int32_t i = (col * (lines + 1)) >> 6;

	s.board[i] = s.board[i] ^ s.mask[i];
	s.mask[i] |= s.mask[i] + ((bitstr_t)1 << (col * (lines + 1)));
}

void init(t_game *game)
{
	t_state s;

	game->nb_cases = game->lines * game->cols + game->cols;
	game->board_len = (game->nb_cases + 63) >> 6;

	printf("here %ld\n", game->board_len * sizeof(bitstr_t));
	s.board = (bitstr_t *)malloc(game->board_len * sizeof(bitstr_t));
	ft_bzero(s.board, game->board_len * sizeof(bitstr_t));

	s.mask = (bitstr_t *)malloc(game->board_len * sizeof(bitstr_t));
	ft_bzero(s.mask, game->board_len * sizeof(bitstr_t));

	game->curr_state = s;

	drop_token(game->lines, game->curr_state, 0);
	drop_token(game->lines, game->curr_state, 3);
	drop_token(game->lines, game->curr_state, 4);
	drop_token(game->lines, game->curr_state, 5);
	drop_token(game->lines, game->curr_state, 6);
	drop_token(game->lines, game->curr_state, 6);
	drop_token(game->lines, game->curr_state, 1);
	drop_token(game->lines, game->curr_state, 2);
	print_board(game, game->curr_state.mask);
}

int is_big_endian(void)
{
	union
	{
		uint32_t i;
		char c[4];
	} e = {0x01000000};

	return e.c[0];
}
int main(int argc, char **argv)
{
	t_game game;

	printf("%d\n", is_big_endian());
	if (argc != 3)
		return (print_err("Must have 2 arguments lines and columns\n"));
	if (str_is_numeric(argv[1], "6", "100"))
		game.lines = ft_atoi(argv[1]);
	else
		return (print_err("lines must be between 6 and 100\n"));
	if (str_is_numeric(argv[2], "7", "100"))
		game.cols = ft_atoi(argv[2]);
	else
		return (print_err("columns must be between 7 and 100\n"));
	init(&game);
	printf("%d\n", check_win(&game, game.curr_state.mask));
	return (0);
}