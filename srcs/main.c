#include "board.h"

int main(int argc, char** argv) {
  t_board* board;
  int input_fd;
  switch (argc)
  {
  case 1:
    input_fd = 1;
    break;
  case 2:
    // input_fd = open_board_file(argv[1]);
    break;
  default:
    // usage: ./alcu [board_file]
    return 1;
  }
  // board = init_board(input_fd);
  // start_game(board);

  (void)board;
  (void)input_fd;
  (void)argv;
  return 0;
}