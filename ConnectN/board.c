#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "playgame.h"
#include "win.h"
//  rows = argv[1], cols = argv[2], num_pieces_to_win = argv[3]
//  ROW NUMBER will correspond to the board game + 1
//  COL NUMBER will correspond to the board game + 1
void setup_game(char*** out_board, int row, int col) {
  *out_board = create_board(row, col);
}

char** create_board(int setrow, int setcol) {
  char** board = (char**)calloc(setrow, sizeof(*board));
  for (int i = 0; i < setrow; i++) {
    board[i] = (char*)calloc(setcol, sizeof(*board[i]));
    for (int j = 0; j < setcol; j++) {
      board[i][j] = '*';
    }
  }
  return board;
}

void print_board(char** board, int setrow, int setcol) {
  for (int row = 0; row < setrow; row++) {
    int row_header = setrow - (row + 1);
    printf("%d ", row_header); //  row headers
    for (int col = 0; col < setcol; col++) {
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }
  printf("  ");
  for (int col = 0; col < setcol; col++) { // col headers
    printf("%d ", col);
  }
}
