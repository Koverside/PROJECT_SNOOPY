#include "header.h"

void chargerPartie(char utilisateur, char tableauNom[MAX], char map[LARGEUR][HAUTEUR + 1])
{
    char chemin[MAX];
    int choix;
    Effacer_ecran();
    printf("Voulez-vous charger une partie ?\n1.Oui\n2.Non\n");
    scanf("%d", &choix);

    switch (choix) {
        case 1: {
            Effacer_ecran();
            printf("Saisir votre nom d'utilisateur\n");
            scanf("%s", &utilisateur);

            sprintf(chemin, "./parties/%s.txt", &utilisateur);
            FILE *partie = fopen(chemin, "r");

            if (partie != NULL) {
                for (int i = 0; i < LARGEUR; i++) {
                    if (fgets(map[i], HAUTEUR + 1, partie) == NULL) {
                        fprintf(stderr, "Erreur de lecture du fichier %s.txt\n", utilisateur);
                        fclose(partie);
                        exit(EXIT_FAILURE);
                    }
                }
                fclose(partie);
                Effacer_ecran();
                affichage();
            } else {
                Effacer_ecran();
                printf("Il n'y a pas de partie enregistrée sous le nom de [%s]\n", utilisateur);
            }
            break;
        }

        case 2:
            Effacer_ecran();
            Affichage_M();
            break;

        default:
            break;
    }
}
