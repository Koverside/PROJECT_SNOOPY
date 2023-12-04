#include "header.h"

void MDP(char utilisateur[])
{
    int nv;
    char MDP_Saisie[20];

    printf("Numero du niveau ");
    scanf("%d", &nv);

    if (nv >= 1 && nv <=3)
    {
        printf("Le mot de passe pour le nv %d est : %s\n", nv, MDP1[nv - 1]);
        printf("Entrez le mot de passe pour le nv %d : ", nv);
        scanf("%s", MDP_Saisie);

        if (verifie_MDP(nv, MDP_Saisie))
        {
            printf("Mot de passe correct. Acces au nv %d autorise.\n", nv);
            // Launch the appropriate level
            switch (nv)
            {
                case 1:
                    Niveau1(utilisateur);
                    break;
                case 2:
                    Niveau2(utilisateur);
                    break;
                case 3:
                    Niveau3(utilisateur);
                    break;
            }
        } else {
            printf("Mot de passe incorrect.\n");
        }
    } else {
        printf("Niveau invalide.\n");
    }
}