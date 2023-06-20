#ifndef WIN_GAME
#define WIN_GAME

bool has_someone_won(char** board, int row, int col, int num_pieces_to_win);
bool has_someone_won_horizontally(char** board, int row, int col, int num_pieces_to_win);
bool has_someone_won_vertically(char** board, int row, int col, int num_pieces_to_win);
bool has_someone_won_right_diagonally(char** board, int row, int col, int num_pieces_to_win);

#endif
