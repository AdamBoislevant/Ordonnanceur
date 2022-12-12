#include "fonctionsSujet2.h"


// Programme principal
int main() {
    ordonnanceur* tete = NULL;
    ordonnanceur* queue = NULL;
    initialisation_ajout(&tete, &queue);
    run(&tete, &queue);
}