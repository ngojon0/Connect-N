#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "board.h"
#include "playgame.h"
#include "win.h"
#include "input.h"

void check_argv(int argc, char* argv[]) {
  if (argc == 4) {
    if ((argv[1] == 0) || (argv[2] == 0) || (argv[3] == 0)) {
      printf("Row, Columns, and num_pieces_to_win > 0 please.");
      exit(0);
    }
  }

  if (argc < 4) {
      printf("Not enough arguments entered\n");
      printf("Usage connectn.out num_rows num_columns ");
      printf("number_of_pieces_in_a_row_needed_to_win");
      exit(0);
  } else if (argc > 4) {
      printf("Too many arguments entered\n");
      printf("Usage connectn.out num_rows num_columns ");
      printf("number_of_pieces_in_a_row_needed_to_win");
      exit(0);
  }
}


int main(int argc, char* argv[]) {
  char** board = NULL;
  int row = 0;
  int col = 0;
  int num_pieces_to_win = 0;

  check_argv(argc, argv);
  sscanf(argv[1], "%d", &row);
  sscanf(argv[2], "%d", &col);
  sscanf(argv[3], "%d", &num_pieces_to_win);

//  start the actual code here

  setup_game(&board, row, col);
  play_game(board, row, col, num_pieces_to_win);
//  in play game, define the starting player and playerpieces



  for (int i = 0; i < row; i++) {
    free(board[i]);
  }
  free(board);

  }
  //  ^ end of actual code
