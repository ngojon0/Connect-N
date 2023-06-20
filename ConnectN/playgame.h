#ifndef PLAY_GAME
#define PLAY_GAME

void play_game(char** board, int row, int col, int num_pieces_to_win);
void get_valid_player_move(char** board, int row, int col, int* outcol);
void make_player_move(char** board, int row, int col, int col_played, int cur_player, char player_pieces[]);
int lowest_place(char** board, int row, int col_played);
bool is_game_over(char** board, int row, int col, int num_pieces_to_win);
bool is_tie_game(char** board, int row, int col, int num_pieces_to_win);


#endif //PLAY_GAME
