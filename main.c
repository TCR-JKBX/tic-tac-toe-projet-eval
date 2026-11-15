#include <stdio.h>
#include "tic-tac-toe.h"

void display_board(char board[9])
{
    printf("\n");
    printf(" %c | %c | %c \n", board[0], board[1], board[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n");
}

int main(void)
{
    char board[9] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    display_board(board);
void player_turn(char board[9])
{
    int position;

    printf("Choisis une case (0 a 8) : ");
    scanf("%d", &position);

    while (position < 0 || position > 8 || board[position] != ' ')
    {
        printf("Case invalide ou deja occupee ! Reessaie : ");
        scanf("%d", &position);
    }

    board[position] = 'X';
}

    return 0;
}
