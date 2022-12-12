#ifndef FONCTIONS_H
#define FONCTIONS_H

// Including necessary libraries 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

// Definition des structures Processus Ordonnanceur
typedef struct processus processus;
struct processus {
    char nom[256];
    int duree;
    int prio;
};

typedef struct ordonnanceur ordonnanceur;
struct ordonnanceur{
    processus proc;
    ordonnanceur* suivant;
};

void ajout_activite(ordonnanceur** tete, ordonnanceur** queue, char* nom, int duree, int priorite);
void initialisation_ajout(ordonnanceur** tete, ordonnanceur** queue);
void step(ordonnanceur** tete, ordonnanceur** queue);
void run(ordonnanceur** tete, ordonnanceur** queue);

#endif