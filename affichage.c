#include "header.h"

void affichage() {

    int x=0;
    system("cls");
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            if ((i == 0 || i == HAUTEUR - 1 || j == 0 || j == LARGEUR - 1) && (x <= (120 - Partie.temps) / 2))
            {
                Color(12,0);
                printf("%c ", map[i][j]);
                x++;
            }
            else
            {
                Color(9,0);
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
    printf("%d secondes restantes\n", Partie.temps);
    printf("%d vies restantes\n", Partie.vies);
}