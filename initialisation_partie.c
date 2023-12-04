#include "header.h"

//PARTIE 1

void initializePartie_1()
{
    Partie.nb_oiseaux = 4;
    Partie.vies = 3;
    Partie.temps = 120;
    Partie.oiseaux_recup = 0;
    Partie.niv=1;

    Partie.Balle_X = 3;
    Partie.Balle_Y = 6;
    Partie.mode = 2;
    Partie.S_Balle = RIEN;

    char map_1[HAUTEUR][LARGEUR] = {
            "NNNNNNNNNNNNNNNNNNNN",
            "NO  #             ON",
            "N   #    ^   ^     N",
            "N   #  P  ^ ^      N",
            "N##C#      ^       N",
            "N                  N",
            "N?                 N",
            "N############C#####N",
            "NO                ON",
            "NNNNNNNNNNNNNNNNNNNN",
    };

    for (int i = 0; i < HAUTEUR; i++) {
        strncpy(map[i], map_1[i], LARGEUR);
    }
}


//PARTIE 2

void initializePartie_2()
{
    Partie.nb_oiseaux = 4;
    Partie.vies = 3;
    Partie.temps = 120;
    Partie.oiseaux_recup = 0;
    Partie.niv=2;

    Partie.Balle_X = 3;
    Partie.Balle_Y = 6;
    Partie.mode=2;
    Partie.S_Balle = RIEN;

    char map_2[HAUTEUR][LARGEUR] = {
            "NNNNNNNNNNNNNNNNNNNN",
            "NO  #             ON",
            "N   #    ^   ^     N",
            "N   #  P  ^ ^      N",
            "N##C#      ^       N",
            "N                  N",
            "N?                 N",
            "N#### #######C#####N",
            "NO                ON",
            "NNNNNNNNNNNNNNNNNNNN",
    };

    for (int i = 0; i < HAUTEUR; i++) {
        strncpy(map[i], map_2[i], LARGEUR);
    }
}


//PARTIE 3

void initializePartie_3()
{
    Partie.nb_oiseaux = 4;
    Partie.vies = 3;
    Partie.temps = 120;
    Partie.oiseaux_recup = 0;
    Partie.niv=3;

    Partie.Balle_X = 3;
    Partie.Balle_Y = 6;
    Partie.mode = 2;
    Partie.S_Balle = RIEN;

    char map_3[HAUTEUR][LARGEUR] = {
            "NNNNNNNNNNNNNNNNNNNN",
            "NO  #             ON",
            "N   #    ^   ^     N",
            "N   #  P  ^ ^      N",
            "N##C#      ^       N",
            "N                  N",
            "N?                 N",
            "N############C#####N",
            "NO                ON",
            "NNNNNNNNNNNNNNNNNNNN",
    };

    for (int i = 0; i < HAUTEUR; i++) {
        strncpy(map[i], map_3[i], LARGEUR);
    }
}