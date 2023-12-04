
#ifndef PROJET_SNOOPY_FINAL_HEADER_H
#define PROJET_SNOOPY_FINAL_HEADER_H

#endif //PROJET_SNOOPY_FINAL_HEADER_H

//Bibliothèques
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <process.h>
#include <time.h>

//Déclaration valeurs
#define MAX 500
#define SNOOPY 'S'
#define RIEN ' '
#define HAUTEUR 10
#define LARGEUR 20
#define OISEAUX 'O'
#define B_POUSSABLE 'P'
#define B_PIEGER '^'
#define B_FIXE '#'
#define B_CASSABLE 'C'
#define B_BORDURE 'N'
#define B_BALLE '*'
#define B_BONNUS '?'

//Déclaration externes
extern HANDLE mutexCompteARebours;
extern struct Partie Partie;
extern char map[HAUTEUR][LARGEUR];  // déclaration de la variable
extern const char* MDP1[]; // déclaration de la variable

//Déclaration structures
struct Partie
{
    int Snoopy_X, Snoopy_Y;
    int Balle_X, Balle_Y, mode;
    char S_Balle;

    int nb_oiseaux;
    int vies;
    int temps;
    int niv;
    int score;

    int oiseaux_recup;
};

//Déclarations fonctions
void Color(int couleurDuTexte,int couleurDeFond);
void affichage();
void Position(char mouvement,char utilisateur[]);
void compteARebours();
int Niveau1(char utilisateur[]);
int Niveau2(char utilisateur[]);
int Niveau3(char utilisateur[]);
int verifie_MDP(int niveau, const char* MDP_Saisie);
void Effacer_ecran();
void Affichage_M();
void Regles();
void nouveau(char utilisateur[]);
void MDP(char utilisateur[]);
void initializePartie_1();
void initializePartie_2();
void initializePartie_3();
void Pause(char utilisateur[]);
void chargerPartie(char utilisateur, char tableauNom[MAX], char map[LARGEUR][HAUTEUR + 1]);
void Sauvegarder (char map[HAUTEUR][LARGEUR], char utilisateur[]);
void Balle();

