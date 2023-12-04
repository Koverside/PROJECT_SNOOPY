#include "header.h"

void compteARebours()
{
    while (Partie.temps > 0)
    {
        WaitForSingleObject(mutexCompteARebours, INFINITE);  // Attend que le mutex soit disponible
        if(Partie.Snoopy_X == Partie.Balle_X && Partie.Snoopy_Y == Partie.Balle_Y)
        {
            Partie.vies=0;
        }
        affichage();
        Sleep(1000);
        Partie.temps--;

        if(Partie.Snoopy_X == Partie.Balle_X && Partie.Snoopy_Y == Partie.Balle_Y)
        {
            Partie.vies=0;
        }

        if (Partie.temps == 0)
        {
            Partie.vies--;
            if (Partie.vies > 0)
            {
                printf("%d vies\n", Partie.vies);
                //B_Pieger();
                Partie.Snoopy_X = HAUTEUR / 2;
                Partie.Snoopy_Y = LARGEUR / 2;
                Partie.temps = 120;
            }
            else
            {
                printf("Game Over\n");
                exit(0);
            }
        }
        ReleaseMutex(mutexCompteARebours);  // Libère le mutex
    }
    _endthread();
}