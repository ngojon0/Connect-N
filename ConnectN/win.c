#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
#include "playgame.h"
#include "win.h"
#include "input.h"

bool has_someone_won(char** board, int row, int col, int num_pieces_to_win) {
  return has_someone_won_horizontally(board, row, col, num_pieces_to_win) ||
         has_someone_won_vertically(board, row, col, num_pieces_to_win) ||
         has_someone_won_right_diagonally(board, row, col, num_pieces_to_win);
}

bool has_someone_won_horizontally(char** board, int row, int col, int num_pieces_to_win) {
  int count = 1;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (board[i][j] != '*') {
        if (board[i][j] == 'X') {
          if (board[i][j + 1] == 'X' && (j < col)) {
            count++;
            if (count == num_pieces_to_win) {
              return true;
            }
          } else {
            count = 1;
          }
        } else {
          if (board[i][j + 1] == 'O' && (j < col)) {
            count++;
            if (count == num_pieces_to_win) {
              return true;
            }
          } else {
            count = 1;
          }
        }
      }
    }
  }
  return false;
}

bool has_someone_won_vertically(char** board, int row, int col, int num_pieces_to_win) {
  int count = 1;
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      if (board[j][i] != '*') {
        if (j < (row-1)) {
          if (board[j][i] == 'X') {
            if (board[j+1][i] == 'X') {
              count++;
              if (count == num_pieces_to_win) {
                return true;
              }
            } else {
              count = 0;
            }
          } else {

            if (board[j+1][i] == 'O') {
              count++;
              if (count == num_pieces_to_win) {
                return true;
              }
            } else {
              count = 0;
            }
          }
        }
      }
    }
  }
  return false;
}

//  for "\"
bool has_someone_won_right_diagonally(char** board, int row, int col, int num_pieces_to_win) {
//  can't make a diagonal at the corners because it won't fit
  for (int i = 0; i < row-num_pieces_to_win; i++) {
    for (int j = 0; j < col-num_pieces_to_win; j++) {
      char place = board[i][j];
      if (board[i][j] != '*') {
        int k;
        for (k = 1; k <= num_pieces_to_win; k++) {
          printf("%d", k);
          if (place != board[i+k][j+k]) {
            break;
          }
        }
        if (k == num_pieces_to_win) {
          return true;
        }
      }
      /*if (place == 'O') {
        int m;
        for (m = 1; m < num_pieces_to_win; m++) {
          if (place != board[i+m][j+m]) {
            break;
          }
        }
        if (m == num_pieces_to_win) {
          return true;
        }
      }*/
    }
  }

  return false;
}
