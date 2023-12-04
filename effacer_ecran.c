#include "header.h"

void Effacer_ecran() {
#ifdef _WIN32
    system("cls");  // Pour Windows
#endif
}