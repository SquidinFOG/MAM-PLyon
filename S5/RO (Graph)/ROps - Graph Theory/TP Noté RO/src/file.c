#include <stdlib.h>
#include <stdio.h>
#include "file.h"

void inserer(file *tete, int val) {
    noeud *courant; 
    noeud *nouveau = malloc(sizeof(noeud));
    if (!nouveau) return;

    nouveau->val = val;
    nouveau->suivant = NULL;

    if(*tete == NULL)
    {
        *tete = nouveau;
    }
    else
    {
        courant = *tete;
        while (courant->suivant != NULL) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
    }
}

int retirer(file *tete) {
    int retval = -1;

    if (*tete == NULL) return retval;

    retval = (*tete)->val;
    *tete = (*tete)->suivant;

    return retval;
}

void afficher_file(file tete) {
    noeud *courant;

    if (tete == NULL){
        printf("La file est vide !\n");
        return;
    }

    courant = tete;
    while (courant != NULL) {
        printf("%d ", courant->val);
        courant = courant->suivant;
    }
    printf("\n");
}
