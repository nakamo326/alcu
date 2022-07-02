#include <fcntl.h>

#include "alcu.h"
#include "libft.h"

int main(int argc, char** argv) {
	t_game	game = {NULL, 0, false};
	int		input_fd;

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
	if (!parse_map(&game, input_fd)) {
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return 1;
	}
	start_game(&game);
	free(game.heap);
	return 0;
}
