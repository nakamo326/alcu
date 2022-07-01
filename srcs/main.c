#include <fcntl.h>


#include "board.h"
#include "libft.h"

int main(int argc, char** argv) {
	t_board*	board;
	int			input_fd;

	switch (argc)
	{
	case 1:
		input_fd = STDIN_FILENO;
		break;
	case 2:
		input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1) {
			ft_putendl_fd("open map file error.", STDERR_FILENO);
			return 1;
		}
		break;
	default:
		ft_putendl_fd("usage: ./alcu [board_file]", STDERR_FILENO);
		return 1;
	}
	// board = init_board(input_fd);
	// start_game(board);

	(void)board;
	(void)input_fd;
	(void)argv;
	return 0;
}