#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "playgame.h"
#include "board.h"
#include "win.h"
#include "input.h"

void play_game(char** board, int row, int col, int num_pieces_to_win) {
  int cur_player = 0;
  char player_pieces[] = "XO";
while (!is_game_over(board, row, col, num_pieces_to_win)) {
  print_board(board, row, col);
  int col_played;
  get_valid_player_move(board, row, col, &col_played);
  make_player_move(board, row, col, col_played, cur_player, player_pieces);
  cur_player = (cur_player + 1) % 2;
}
  cur_player = (cur_player + 1) % 2;
  print_board(board, row, col);
  if (is_tie_game(board, row, col, num_pieces_to_win) == true) {
    printf("\nTie game!\n");
  } else {
    printf("\nPlayer %d Won!\n", cur_player + 1);
  }
}

bool is_game_over(char** board, int row, int col, int num_pieces_to_win) {
  return has_someone_won(board, row, col, num_pieces_to_win) || is_tie_game(board, row, col, num_pieces_to_win);
}

bool is_tie_game(char** board, int row, int col, int num_pieces_to_win) {
  if (has_someone_won(board, row, col, num_pieces_to_win)) {
    return false;
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] == '*') {
        return false;
      }
    }
  }
  return true;
}



void get_valid_player_move(char** board, int row, int col, int* outcol) {
  *outcol = getValidIntInRange(0, col-1);
}

void make_player_move(char** board, int row, int col, int col_played, int cur_player, char player_pieces[]) {
  int open_spot = lowest_place(board, row, col_played);
  if (cur_player == 0) {
    board[open_spot][col_played] = player_pieces[0];
  } else {
    board[open_spot][col_played] = player_pieces[1];
  }
}


int lowest_place(char** board, int row, int col_played) {
  int i;
  for (i = row - 1; i >= 0; i--) {
    if (board[i][col_played] == '*') {
      break;
    } else {
      continue;
    }
  }
  return i;
}
