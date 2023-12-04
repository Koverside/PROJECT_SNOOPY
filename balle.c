#include "header.h"

void Balle()
{
    map[Partie.Balle_X][Partie.Balle_Y]=Partie.S_Balle;
    int temporaire;
    temporaire = Partie.temps;
    if (temporaire!=Partie.temps)
    {
        map[Partie.Balle_X][Partie.Balle_Y]=Partie.S_Balle;

        if((map[Partie.Balle_X + 1][Partie.Balle_Y + 1] == B_BORDURE && map[Partie.Balle_X - 1][Partie.Balle_Y + 1] != B_BORDURE && Partie.mode == 1) || (map[Partie.Balle_X - 1][Partie.Balle_Y - 1] == B_BORDURE && map[Partie.Balle_X - 1][Partie.Balle_Y + 1] != B_BORDURE && Partie.mode == 3))
        {
            Partie.mode=2;
        }
        if((map[Partie.Balle_X - 1][Partie.Balle_Y + 1] == B_BORDURE && map[Partie.Balle_X - 1][Partie.Balle_Y - 1] != B_BORDURE && Partie.mode == 2) || (map[Partie.Balle_X + 1][Partie.Balle_Y + 1] == B_BORDURE && map[Partie.Balle_X - 1][Partie.Balle_Y - 1] != B_BORDURE && Partie.mode == 4))
        {
            Partie.mode=3;
        }
        if((map[Partie.Balle_X + 1][Partie.Balle_Y - 1] == B_BORDURE && map[Partie.Balle_X + 1][Partie.Balle_Y + 1] != B_BORDURE && Partie.mode == 4) || (map[Partie.Balle_X - 1][Partie.Balle_Y + 1] == B_BORDURE && map[Partie.Balle_X + 1][Partie.Balle_Y + 1] != B_BORDURE && Partie.mode == 2))
        {
            Partie.mode=1;
        }
        if((map[Partie.Balle_X - 1][Partie.Balle_Y - 1] == B_BORDURE && map[Partie.Balle_X + 1][Partie.Balle_Y - 1] != B_BORDURE && Partie.mode == 3) || (map[Partie.Balle_X + 1][Partie.Balle_Y + 1] == B_BORDURE && map[Partie.Balle_X + 1][Partie.Balle_Y - 1] != B_BORDURE && Partie.mode == 1))
        {
            Partie.mode=4;
        }
        switch (Partie.mode)
        {
            case 1:
                Partie.S_Balle = map[Partie.Balle_X + 1][Partie.Balle_Y + 1];
                Partie.Balle_X++;
                Partie.Balle_Y++;
                break;
            case 2:
                Partie.S_Balle = map[Partie.Balle_X - 1][Partie.Balle_Y + 1];
                Partie.Balle_X--;
                Partie.Balle_Y++;
                break;
            case 3:
                Partie.S_Balle = map[Partie.Balle_X - 1][Partie.Balle_Y - 1];
                Partie.Balle_X--;
                Partie.Balle_Y--;
                break;
            case 4:
                Partie.S_Balle = map[Partie.Balle_X + 1][Partie.Balle_Y - 1];
                Partie.Balle_X++;
                Partie.Balle_Y--;
                break;
        }
        map[Partie.Balle_X][Partie.Balle_Y]=B_BALLE;
    }
    map[Partie.Balle_X][Partie.Balle_Y]=B_BALLE;
}