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

void player_turn(char board[9])
{
    int position;

    printf("Choisis une case (0 a 8) : ");

    while (scanf("%d", &position) != 1
        || position < 0
        || position > 8
        || board[position] != ' ')
    {
        printf("Case invalide ou deja occupee ! Reessaie : ");

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (c == EOF)
            return;
    }

    board[position] = 'X';
}

void computer_turn(char board[9])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
        {
            board[i] = 'O';
            printf("L'ordinateur joue en case %d.\n", i);
            return;
        }
    }
}

char check_winner(char board[9])
{
    int combinations[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    int i;

    for (i = 0; i < 8; i++)
    {
        if (board[combinations[i][0]] != ' '
            && board[combinations[i][0]] == board[combinations[i][1]]
            && board[combinations[i][1]] == board[combinations[i][2]])
        {
            return board[combinations[i][0]];
        }
    }

    return ' ';
}

int board_full(char board[9])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ')
            return 0;
    }

    return 1;
}

int main(void)
{
    char board[9] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    char winner = ' ';

    printf("Bienvenue dans le jeu du morpion !\n");

    while (winner == ' ' && !board_full(board))
    {
        display_board(board);

        player_turn(board);

        winner = check_winner(board);

        if (winner != ' ' || board_full(board))
            break;

        computer_turn(board);

        winner = check_winner(board);
    }

    display_board(board);

    if (winner == 'X')
        printf("Bravo ! Tu as gagne !\n");
    else if (winner == 'O')
        printf("L'ordinateur a gagne !\n");
    else
        printf("Match nul !\n");

    return 0;
}

