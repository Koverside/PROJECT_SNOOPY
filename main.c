#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "snoopy.h"


//MDP de chaque niv
const char* M_D_P[] = {"MDP_1", "MDP_2", "MDP_3"};

//MDP correct ?
int verifie_MDP(int niveau, const char* MDP_Saisie) {
    if (strcmp(MDP_Saisie, M_D_P[niveau - 1]) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void Effacer_ecran() {
#ifdef _WIN32
    system("cls");  // Pour Windows
#else
    system("clear");  // Pour Unix/Linux
#endif
}

void Affichage_M() {
    printf("        SNOOPY MAGIC SHOW \n");
    printf(" 1- Regles du jeu \n");
    printf(" 2- Nouvelles partie \n");
    printf(" 3- Partie en cours \n");
    printf(" 4- Mot de passe \n");
    printf(" 5- Scores \n");
    printf(" 6- Quitter \n");}

void Regles() {
    printf("Regles du jeu :\n");
    printf("---------------------------------------------------------------------\n");
    printf("-Snoopy est un chien qui doit collecter 4 oiseaux dans chaque niveau.\n");
    printf("-Il doit eviter d'etre touche par la balle ou les ennemis, s'ils sont presents.\n");
    printf("-Le jeu comporte plusieurs niveaux de difficulte croissante.\n");
    printf("-Chaque niveau doit etre termine en moins de 120 secondes.\n");
    printf("-Si le temps est ecoule, le joueur perd une vie et recommence le niveau.\n");
    printf("-Snoopy peut se deplacer vers le haut, le bas, la gauche et la droite.\n");
    printf("-La balle se deplace en diagonale et rebondit sur les murs du niveau.\n");
    printf("-Snoopy ne peut pas sortir du niveau.\n");
    printf("-Gagnez en recuperant les 4 oiseaux. Une fois le niveau termine, le suivant commence.\n");
    printf("-Le jeu se termine si le joueur perd toutes ses vies.\n");
    printf("-Les scores sont calcules en fonction du temps restant.\n");
    printf("Bon jeu !\n");
    printf("---------------------------------------------------------------------\n");
}

void nouveau() {
    printf("Lancer un nouveau jeu à partir du niveau 1... \n");
    Niveau1();
    return(Affichage_M());
}

void MDP() {
    int nv;
    char MDP_Saisie[20];

    printf("Numero du niveau ");
    scanf("%d", &nv);

    if (nv >= 1 && nv <= sizeof(M_D_P) / sizeof(M_D_P[0])) {
        printf("Le mot de passe pour le nv %d est : %s\n", nv, M_D_P[nv - 1]);
        printf("Entrez le mot de passe pour le nv %d : ", nv);
        scanf("%s", MDP_Saisie);

        if (verifie_MDP(nv, MDP_Saisie)) {
            printf("Mot de passe correct. Accès au nv %d autorisé.\n", Niveau1());
        } else {
            printf("Mot de passe incorrect.\n");
        }
    } else {
        printf("Niveau invalide.\n");
    }
}

int main() {
    int i; //choix
    bool Menu = true;
    int niveauCourant = 1;

    do {
        if (Menu) {
            Affichage_M();}
        printf("Faites votre choix : ");
        scanf("%d", &i);

        switch (i) {
            case 1:
                Effacer_ecran();
                Regles();
                Menu = false;
                break;
            case 2:
                Effacer_ecran();
                nouveau();
                break;
            case 3:
                Effacer_ecran();
                charger();
                break;
            case 4:
                Effacer_ecran();
                MDP();
                printf("Félicitations ! Snoopie a mangé tous les oiseaux aux extrémités.\n");
                break;
            case 5:
                Effacer_ecran();
                break;
            case 6:
                Effacer_ecran();
                break;
            default:
        }
    } while (i != 6);

    return 0;
}

