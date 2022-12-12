#include "fonctionsSujet2.h"


// b. Ajout d'activité
void ajout_activite(ordonnanceur** tete, ordonnanceur** queue, char* nom, int duree, int priorite){
    ordonnanceur *nouveau = (ordonnanceur*)malloc(sizeof(ordonnanceur));

    if (nouveau == NULL){
        printf("ERREUR ORDONNANCEUR");
        exit(EXIT_FAILURE);
    }

    processus proc;
    strcpy(proc.nom, nom);
    proc.duree = duree;
    proc.prio = priorite;

    nouveau->proc = proc;
    nouveau->suivant = NULL;

    if(*queue) (*queue)->suivant = nouveau;
    else (*tete) = nouveau;
    (*queue) = nouveau;
}

// e. Programme demandant les paramètres à entrer dans l'ordre
void initialisation_ajout(ordonnanceur** tete, ordonnanceur** queue){
    char nom[256];
    int duree;
    int priorite;
    int n;

    printf("Combien de processus voulez vous ajouter? ");
    scanf("%d", &n);

    for(int i=1 ; i<=n ; i++){
        printf("entrez le nom du processus numéro %d: ", i);
        scanf("%s", nom);
        printf("entrez la duree d'execution du processus numéro %d: ", i);
        scanf("%d", &duree);
        printf("entrez la priorite du processus numéro %d: ", i);
        scanf("%d", &priorite);
        printf("\n");
        while(priorite < 0 || priorite > 5){
            printf("veuillez entrer une valeur de priorite valide.\n");
            scanf("%d", &priorite);
        }
        ajout_activite(tete, queue, nom, duree, priorite);
    }
}

//c. fonction step
void step(ordonnanceur** tete, ordonnanceur** queue){
    ordonnanceur* ordo = *tete;

    printf("récapitulatif des processus à effectuer:\n\n");
    while(ordo != NULL){
        printf("%s, %d, %d\n", ordo->proc.nom, ordo->proc.duree, ordo->proc.prio);
        ordo = ordo->suivant;
    }

    if (tete == NULL){
        printf("ORDONNANCEUR INEXISTANT!!");
        exit(EXIT_FAILURE);
    }

    ordo = *tete;
    if(ordo != NULL){
        *tete = ordo->suivant;

        if(*queue == ordo) *queue = NULL;

        printf("Execution du processus: %s\ndurée d'execution: %d secondes\n", ordo->proc.nom, ordo->proc.duree);
        sleep(ordo->proc.duree);
        free(ordo);
    }else{
        printf("Il n'y à aucun processus à effectué\n");
        exit(1);
    }
    return;
}

// d. Fonction run
void run(ordonnanceur** tete, ordonnanceur** queue){
    while(*tete != NULL){
        step(tete, queue);
    }
}