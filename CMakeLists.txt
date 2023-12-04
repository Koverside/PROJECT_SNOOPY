cmake_minimum_required(VERSION 3.26)
project(PROJET_SNOOPY_FINAL C)

set(CMAKE_C_STANDARD 99)

add_executable(PROJET_SNOOPY_FINAL main.c
        header.h
        effacer_ecran.c
        affichage_menu.c
        regles.c
        nouveau.c
        mdp.c
        initialisation_partie.c
        affichage.c
        touches.c
        compte_a_rebours.c
        niveau_1.c
        sauvegarder.c
        charger_partie.c
        pause.c
        balle.c
        verifier_mdp.c
        couleur.c
        definition.c
        niveau_2.c
        niveau_3.c)
