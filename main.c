#include "header.h"

HANDLE mutexCompteARebours;
struct Partie Partie;

int main()
{
    mutexCompteARebours = CreateMutex(NULL, FALSE, NULL);
    int i;
    int score=0;
    bool Menu = true;
    char utilisateur[] = "Kevin Durant MVP";

    do {
        if (Menu)
        {
            Affichage_M();
        }
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
                nouveau(utilisateur);
                break;
            case 3:
                Effacer_ecran();
                //chargerPartie(utilisateur[MAX], tableauNom);
                break;
            case 4:
                Effacer_ecran();
                MDP(utilisateur);
                break;
            case 5:
                Effacer_ecran();
                break;
            case 6:
                Effacer_ecran();
                break;
            default:
        }
    }
    while (i != 6);
    return 0;
}
