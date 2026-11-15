#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

void display_board(char board[9]);
void player_turn(char board[9]);
void computer_turn(char board[9]);
char check_winner(char board[9]);
int board_full(char board[9]);

#endif

