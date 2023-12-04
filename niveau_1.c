#include "header.h"

int Niveau1(char utilisateur[])
{
    srand(time(NULL));
    initializePartie_1(utilisateur);

    Color(9,0);

    Partie.Snoopy_X = HAUTEUR / 2;
    Partie.Snoopy_Y = LARGEUR / 2;
    map[Partie.Snoopy_X][Partie.Snoopy_Y] = SNOOPY;

    affichage();

    _beginthread((_beginthread_proc_type)compteARebours, 0, (void*)&Partie.temps);

    while (Partie.vies > 0)
    {
        char mouvement = _getch();
        WaitForSingleObject(mutexCompteARebours, INFINITE);  // Attend que le mutex soit disponible
        Position(mouvement,utilisateur);
        ReleaseMutex(mutexCompteARebours);  // Libère le mutex
        affichage();
    }

    return 0;
}