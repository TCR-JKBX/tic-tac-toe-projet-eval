
#include <stdio.h> // Bibliothèque standard
#include "tic-tac-toe.h" // Header

// Affichage du plateau
void display_board(char board[9])
{
    printf("\n"); // Saut de ligne
    printf(" %c | %c | %c \n", board[0], board[1], board[2]); // Ligne 1
    printf("---+---+---\n"); // Séparation
    printf(" %c | %c | %c \n", board[3], board[4], board[5]); // Ligne 2
    printf("---+---+---\n"); // Séparation
    printf(" %c | %c | %c \n", board[6], board[7], board[8]); // Ligne 3
    printf("\n"); // Saut de ligne
}

// Tour du joueur
void player_turn(char board[9])
{
    int position; // Case choisie

    printf("Choisis une case (0 a 8) : "); // Demande de saisie

    // Vérif. de la saisie
    while (scanf("%d", &position) != 1
        || position < 0
        || position > 8
        || board[position] != ' ')
    {
        printf("Case invalide ou deja occupee ! Reessaie : "); // Erreur de saisie

        int c; // Caractère temporaire

        // Vidage du buffer
        while ((c = getchar()) != '\n' && c != EOF)
            ;

        if (c == EOF) // Fin de saisie
            return;
    }

    board[position] = 'X'; // Placement du X
}

// Tour de l'ordinateur
void computer_turn(char board[9])
{
    int i; // Compteur

    // Recherche d'une case libre
    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ') // Case vide
        {
            board[i] = 'O'; // Placement du O
            printf("L'ordinateur joue en case %d.\n", i); // Annonce du coup
            return; // Fin du tour
        }
    }
}

// Vérif. du gagnant
char check_winner(char board[9])
{
    // Combinaisons gagnantes
    int combinations[8][3] = {
        {0, 1, 2}, // Ligne 1
        {3, 4, 5}, // Ligne 2
        {6, 7, 8}, // Ligne 3
        {0, 3, 6}, // Colonne 1
        {1, 4, 7}, // Colonne 2
        {2, 5, 8}, // Colonne 3
        {0, 4, 8}, // Diagonale 1
        {2, 4, 6}  // Diagonale 2
    };

    int i; // Compteur

    // Parcours des combinaisons
    for (i = 0; i < 8; i++)
    {
        // Vérif. des 3 cases
        if (board[combinations[i][0]] != ' '
            && board[combinations[i][0]] == board[combinations[i][1]]
            && board[combinations[i][1]] == board[combinations[i][2]])
        {
            return board[combinations[i][0]]; // Symbole gagnant
        }
    }

    return ' '; // Aucun gagnant
}

// Vérif. plateau plein
int board_full(char board[9])
{
    int i; // Compteur

    // Parcours des cases
    for (i = 0; i < 9; i++)
    {
        if (board[i] == ' ') // Case libre
            return 0; // Plateau incomplet
    }

    return 1; // Plateau plein
}

// Fonction principale
int main(void)
{
    // Initialisation du plateau
    char board[9] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    char winner = ' '; // Aucun gagnant

    printf("Bienvenue dans le jeu du morpion !\n"); // Message d'accueil

    // Boucle principale du jeu
    while (winner == ' ' && !board_full(board))
    {
        display_board(board); // Affichage du plateau

        player_turn(board); // Tour du joueur

        winner = check_winner(board); // Vérif. victoire

        // Fin de partie
        if (winner != ' ' || board_full(board))
            break;

        computer_turn(board); // Tour ordinateur

        winner = check_winner(board); // Vérif. victoire
    }

    display_board(board); // Affichage final

    // Résultat de la partie
    if (winner == 'X')
        printf("Bravo ! Tu as gagne !\n");

    else if (winner == 'O')
        printf("L'ordinateur a gagne !\n");

    else
        printf("Match nul !\n"); // Égalité

    return 0; // Fin du programme
}


