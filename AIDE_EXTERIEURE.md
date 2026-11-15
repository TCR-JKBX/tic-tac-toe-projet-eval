AIDE EXTERIEURE.MD

Cours : 

Base du makefile, adapté pour tic tac toee
Fonctions et notions diverses et variées


Discussion privée Discord :

fonction "void display_board(char board[9]);" retrouvée dans main.c et tic-tac-toe.h (on va dire "ttt.h")
+ l'explication de son fonctionnement


IA : 
Correction de l'indentation (je suis encore sur VIM, pas moyen d'ouvrir ca dans VSC)
La partie de code suivant dans le main.c : 
    char board[9] = {
        ' ', ' ', ' ',
        ' ', ' ', ' ',
        ' ', ' ', ' '
(Utilisé en dernier recours, impossible de mettre les , et les ' dans le bon sens)

Explication avec un peu de pseudo code pour expliquer comment implémenter la joueur 2 robot dans le morpion


Le canard en plastique : 

🦆 Vérifier la ponctuation : ";" "()" "{}" "[]"
🦆 char board ça crée le tableau
🦆 display board ca fait ce tableau en grille de morpion
🦆 pour compiler : make puis ./tic-tac-toe
🦆 Faudra créer un README.md pour savoir comment jouer non ? Si, il faudra.
