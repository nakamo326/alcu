#include <fcntl.h>

#include "alcu.h"
#include "bonus.h"
#include "libft.h"

static bool is_bonus_flag(char *arg) {
	size_t len = ft_strlen(arg);
	if (len != 2) {
		return false;
	}
	return arg[0] == '-' && arg[1] == 'b' && arg[2] == '\0';
}

static int open_map_file(char *file_path) {
	int input_fd = open(file_path, O_RDONLY);
	if (input_fd == -1) {
		ft_putendl_fd("open map file error.", STDERR_FILENO);
		return -1;
	}
	return input_fd;
}

static int parse_arg(int argc, char**argv, bool *is_bonus) {
	int input_fd = -1;

	switch (argc)
	{
	case 1:
		input_fd = STDIN_FILENO;
		break;
	case 2:
		*is_bonus = is_bonus_flag(argv[1]);
		if (*is_bonus) {
			return STDIN_FILENO;
		}
		input_fd = open_map_file(argv[1]);
		if (input_fd == -1) {
			return -1;
		}
		break;
	case 3:
		*is_bonus = is_bonus_flag(argv[1]);
		if (!*is_bonus) {
			ft_putendl_fd("usage: ./alcu [-b] [map_file]", STDERR_FILENO);
			return -1;
		}
		input_fd = open_map_file(argv[2]);
		if (input_fd == -1) {
			return -1;
		}
		break;
	default:
		ft_putendl_fd("usage: ./alcu [-b] [map_file]", STDERR_FILENO);
		return -1;
	}
	return input_fd;
}

int main(int argc, char** argv) {
	t_game	game = {NULL, 0, false};
	int		input_fd;
	bool	is_bonus = false;

	input_fd = parse_arg(argc, argv, &is_bonus);
	if (input_fd == -1) {
		return 1;
	}
	if (!parse_map(&game, input_fd)) {
		ft_putendl_fd("ERROR", STDERR_FILENO);
		return 1;
	}
	init_mode(&game);
	if (is_bonus) {
		start_bonus_game(&game);
	} else {
		start_game(&game);
	}
	free(game.heap);
	return 0;
}
