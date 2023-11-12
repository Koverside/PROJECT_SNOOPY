
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <time.h>


#define SNOOPY 'S'
#define RIEN ' '
#define HAUTEUR 10
#define LARGEUR 20
#define OISEAUX 'O'
#define B_POUSSABLE 'P'
#define B_PIEGER 'A'




char map[HAUTEUR][LARGEUR] = {
        "####################",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "#                  #",
        "####################",
};

int Snoopy_X, Snoopy_Y;
int Block_X, Block_Y;
int B_PIEGER_X, B_PIEGER_Y;

int nb_oiseaux = 4;
int vies = 3;
int temps = 120;

int oiseaux_restant = 0;

void affichage() {
    system("cls");
    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void B_Poussable() {
    Block_X = HAUTEUR / 2 - 2;
    Block_Y = LARGEUR / 2 - 2;
    map[Block_X][Block_Y] = B_POUSSABLE;
}

void B_Pieger() {
    do {
        B_PIEGER_X = 1 + rand() % (HAUTEUR - 2);
        B_PIEGER_Y = 1 + rand() % (LARGEUR - 2);
    } while (map[B_PIEGER_X][B_PIEGER_Y] != RIEN);

    map[B_PIEGER_X][B_PIEGER_Y] = B_PIEGER;
}

void Position(char mouvement) {
    int Snoopy2_X = Snoopy_X; //Ancienne position snoopy x
    int Snoopy2_Y = Snoopy_Y; //Ancienne position snoopy y
    int Block2_X = Block_X; //Ancienne position bloc x
    int Block2_Y = Block_Y; //Ancienne position bloc y

    map[Snoopy2_X][Snoopy2_Y] = RIEN;
    map[Block2_X][Block2_Y] = RIEN;

    switch (mouvement) {
        case 'q':
            if (Snoopy_Y > 1) {
                if (Snoopy_Y - Block_Y == 1 && Snoopy_X == Block_X) {
                    Block_Y--;
                    Snoopy_Y--;
                } else {
                    Snoopy_Y--;
                }
            }
            break;
        case 'd':
            if (Snoopy_Y < LARGEUR - 2) {
                if (Block_Y - Snoopy_Y == 1 && Snoopy_X == Block_X) {
                    Block_Y++;
                    Snoopy_Y++;
                } else {
                    Snoopy_Y++;
                }
            }
            break;
        case 's':
            if (Snoopy_X < HAUTEUR - 2) {
                if (Block_X - Snoopy_X == 1 && Snoopy_Y == Block_Y) {
                    Block_X++;
                    Snoopy_X++;
                } else {
                    Snoopy_X++;
                }
            }
            break;
        case 'z':
            if (Snoopy_X > 1) {
                if (Snoopy_X - Block_X == 1 && Snoopy_Y == Block_Y) {
                    Block_X--;
                    Snoopy_X--;
                } else {
                    Snoopy_X--;
                }
            }
            break;
        }

    if (map[Snoopy_X][Snoopy_Y] == B_PIEGER) {
        vies--; //Piege = -1 vies

        if (vies > 0) {
            printf("%d vies restantes\n", vies);
            B_Poussable();
            B_Pieger();
        } else {
            exit(0);
        }
    } else {
        if (map[Snoopy_X][Snoopy_Y] == OISEAUX) {
            oiseaux_restant++; // -1 oiseaux
            map[Snoopy_X][Snoopy_Y] = SNOOPY;
            if (oiseaux_restant == nb_oiseaux) {
                exit(0); //Gagner
            }
        } else {
            map[Snoopy_X][Snoopy_Y] = SNOOPY;
        }
        map[Block_X][Block_Y] = B_POUSSABLE;
    }
}

void compteARebours() {
    while (temps > 0) {
        printf("%d secondes restantes\n", temps);
        Sleep(1000);
        temps--;

        if (temps == 0) {
            vies--;

            if (vies > 0) {
                printf("%d vies\n", vies);
                B_Poussable();
                B_Pieger();
                Snoopy_X = HAUTEUR / 2;
                Snoopy_Y = LARGEUR / 2;
                temps = 120;
            } else {
                printf("Game Over\n");
                exit(0);
            }
        }
    }
}

int Niveau1() {
    srand(time(NULL));

    Snoopy_X = HAUTEUR / 2;
    Snoopy_Y = LARGEUR / 2;

    map[1][1] = OISEAUX;
    map[1][LARGEUR - 2] = OISEAUX;
    map[HAUTEUR - 2][1] = OISEAUX;
    map[HAUTEUR - 2][LARGEUR - 2] = OISEAUX;

    B_Poussable();
    B_Pieger();

    affichage();

    _beginthread(compteARebours, 0, NULL);

    while (vies > 0) {
        if (_kbhit()) {
            char mouvement = _getch();
            Position(mouvement);
            affichage();
        }
    }
    return 0;
}